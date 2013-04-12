/******************************************************************************
 fltk prozilla - a front end for prozilla, a download accelerator library
 Copyright (C) 2001 Kalum Somaratna

 FLTK PROZGUI - a GUI download accelerator
 Copyright (C) 2011 Raviyanto Ahmad

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
******************************************************************************/

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include <malloc.h>
#include <alloca.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>
#include "main.h"
#include "download_win.h"
#include "dl_win.h"

#define _FILE_OFFSET_BITS 64
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


void cb_dl_window(Fl_Window * widget, void *)
{

  DL_Window *dl_window = (DL_Window *) widget;

if (dl_window->status != DL_IDLING)
  {
    if (fl_ask(_("Are you Sure You want to quit?")) == 1) 
    {
      dl_window->cleanup(FALSE);
    }
  } else
    dl_window->cleanup(FALSE);
}

void DL_Window::cleanup(boolean erase_dlparts)
{

  /*handle cleanup */
  if (status == DL_DOWNLOADING)
  {
    proz_download_stop_downloads(download);
    if (erase_dlparts == TRUE)
    {
           proz_download_delete_dl_file(download);
           proz_log_delete_logfile(download);
    }
  } else if (status == DL_GETTING_INFO)
  {
    /*terminate info thread */
    pthread_cancel(info_thread);
    pthread_join(info_thread, NULL);
  } else if (status == DL_JOINING)
  {
    /*terminate joining thread */
   proz_download_cancel_joining_thread(download);
    pthread_join(download->join_thread, NULL);
    join_gui->win->hide();
  }
  else if (status== DL_FTPSEARCHING)
    {
      ftpsearch_win->cleanup();
    }

  hide();
  join_gui->win->hide();
  message_gui->win->hide();
  ask_gui->win->hide();;
  choice_gui->win->hide();
  ftpsearch_win->hide();

  status= DL_ABORTED;
}

DL_Window::DL_Window(urlinfo * url_data, Fl_Boxtype b, int x, int y,
		     const char *l):dl_gui()
{
  box(b);
  key = 0;
  got_info = FALSE;
  got_dl = FALSE;
  status = DL_IDLING;


  memcpy(&u, url_data, sizeof(u));
  memset(&update_time, 0, sizeof(struct timeval));
  num_connections = rt.num_connections;

  join_gui = new dl_join_gui();
  message_gui = new flproz_message();
  ask_gui = new flproz_ask();
  choice_gui = new flproz_choice();
  ftpsearch_win = new FTPS_Window();
  //join_win->hide();
  message_gui->running = FALSE;
  ask_gui->running = FALSE;
  choice_gui->running = FALSE;
  join_gui->running = FALSE;
  joining_thread_running = FALSE;
  do_ftpsearch = FALSE;
  using_ftpsearch = FALSE;
  end();

}

void DL_Window::scroll_browser_to_end()
{
  if (browser->size() > 0)
    browser->bottomline(browser->size());

}

void DL_Window::my_cb()
{
  if (status == DL_GETTING_INFO)
  {
    handle_info_thread();
    return;
  }


  // if ((got_info == TRUE && status == DL_IDLING && got_dl == FALSE)
     if((status == DL_RESTARTING && got_info == TRUE)||status== DL_DLPRESTART)
  {
    do_download();
  }

  if (status == DL_DOWNLOADING)
  {
    handle_download_thread();
    return;
  }

  if (status == DL_JOINING)
  {
    handle_joining_thread();
    return;
  }

  if (status == DL_FATALERR)
  {
    handle_dl_fatal_error();
    return;
  }

  if (status == DL_PAUSED)
  {
    //TODO what to do when paused 
    return;
  }
  if (status == DL_FTPSEARCHING)
  {
    handle_ftpsearch();
    return;
  }


}



void DL_Window::dl_start(int num_connections, boolean ftpsearch)
{

  do_ftpsearch = ftpsearch;

  connection =   proz_connection_init(&u, &getinfo_mutex);
  proz_connection_set_msg_proc(connection, ms, this);

  url_box->value(u.url);
  browser->add(_("Creating the thread that gets info about file"));


  proz_get_url_info_loop(connection, &info_thread);

  status = DL_GETTING_INFO;
}


void DL_Window::do_download()
{
  char buffer[MAX_MSG_SIZE];
  logfile lf;

  status= DL_DLPRESTART;

  if (ask_gui->running == TRUE)
  {
    if (ask_gui->yes_button_pressed == TRUE)	/*delete the file then */
    {
      ask_gui->win->hide();
      ask_gui->running = FALSE;
      if (proz_download_delete_target(download) == -1)
      {
	browser->add(_("I am unable to delete the target file!"));
      }
      handle_prev_download();
      return;
    }
    if (ask_gui->no_button_pressed == TRUE)
    {
      ask_gui->win->hide();
      ask_gui->running = FALSE;
      /*TODO abort the dl */
      status = DL_ABORTED;
      cleanup(FALSE);
      //      handle_prev_download();
      return;
    }
    return;
  }


  if (choice_gui->running == TRUE)
  {
    /*The choice gui is running..monitor whats hapenning */
    if (choice_gui->button1_pressed == TRUE)	//Button 1 is Resume
    {
      choice_gui->win->hide();
      choice_gui->running = FALSE;
      /*Resume selected */
      //Read the logfile structure 
      if (proz_log_read_logfile(&lf, download, FALSE) != 1)
      {
	browser->
	    add
	    (_
	     ("A error occured while processing the logfile! Assuming default number of connections"));
      }
      // validate the info returned
      //TODO check whether files size is the same and if not prompt the user what to do.
      if (lf.num_connections != num_connections)
      {
	browser->
	    add
	    (_
	     ("The previous download used a different number of connections than the default! so I will use the previous number of threads"));
	num_connections = lf.num_connections;
	assert(num_connections > 0);
	// cleanup(FALSE);
      }
      download->resume_mode = TRUE;
      start_download();
      return;
    } else if (choice_gui->button2_pressed == TRUE)	//button 2 is overwrite
    {
      choice_gui->win->hide();
      choice_gui->running = FALSE;

      /*Overwrite selected */
      /*delete the downloads */
      if (proz_log_read_logfile(&lf, download, FALSE) != 1)
      {
	browser->
	    add
	    (_
	     ("A error occured while processing the logfile! Assuming default number of connections to delete"));
	download->num_connections = 4;
      } else
	proz_download_delete_dl_file(download);
      download->resume_mode = FALSE;
      // cleanup(FALSE);
      start_download();
      return;
    } else
      return;			/*Just return if nothing has been pressed */
  }


  /*setup the download */
  download = proz_download_init(&connection->u);
  proz_download_set_msg_proc(download, ms, this);

  /*Check and see whether the target exists and whether to overwrite it */

  if (proz_download_target_exist(download) == 1)
  {

    snprintf(buffer, MAX_MSG_SIZE,
	     _
	     ("The target file %s exists, would you like to overwrite it?"),
	     connection->u.file);

    ask_gui->set_label(buffer);
    ask_gui->win->show();
    ask_gui_type = DLG_TARGETERASE;
    ask_gui->running = TRUE;
    return;
  }

  handle_prev_download();
}

void DL_Window::handle_prev_download()
{
  char buffer[MAX_MSG_SIZE];
  /*Check for a prior download */
  int previous_dl = proz_download_prev_download_exists(download);
  if (previous_dl == 1)
  {

    /*TODO: Check if the server supports resume */

    if (connection->resume_support)
    {

      snprintf(buffer, MAX_MSG_SIZE,
	       _
	       ("Previous download of %s exists, would you like to resume it or overwrite it?"),
	       connection->u.file);

      choice_gui->set_label(buffer);
      choice_gui->set_button1_label(_("Resume"));
      choice_gui->set_button2_label(_("Overwrite"));
      choice_gui->win->show();
      choice_gui_type = DLG_PREVRESUME;
      choice_gui->running = TRUE;
      return;
    }
  }

  start_download();
}



void DL_Window::start_download()
{

  char buffer[MAX_MSG_SIZE];
  int ret=0;

  if (using_ftpsearch != TRUE)
    ret = num_connections = proz_download_setup_connections_no_ftpsearch
	(download, connection, num_connections);
  else
    ret = proz_download_setup_connections_ftpsearch(download,
					      connection,
					      ftpsearch_win->request,
					      num_connections);

  if(ret==-1)
    {
      fl_message(_("Not enough storage space or storage media fails to create file"));
    status = DL_ABORTED;
    return; 
    }

  fls = new Fl_Output *[num_connections];

  /* Add the scrolling info display */
  for (int i = 0; i < num_connections; i++)
  {
    fls[i] = new Fl_Output(22, 48 + (20 * i + 5), 465, 20);
    fls[i]->value("");
    fls[i]->box(FL_FLAT_BOX);
    fls[i]->show();
    fls[i]->color(FL_GRAY);
    scroll_win->add(fls[i]);
  }
  scroll_win->end();

  /*Display resume status */
  if (download->resume_support)
  {
    sprintf(buffer, _("RESUME supported"));
    resume_status_box->textcolor(FL_BLUE);
    resume_status_box->value(buffer);

    resume_later_button->show();
    no_resume_later_button->show();
  } else
  {
    sprintf(buffer, _("RESUME NOT supported"));
    resume_status_box->textcolor(FL_RED);
    resume_status_box->value(buffer);
    resume_later_button->hide();

    no_resume_later_button->show();

  }
  resume_status_box->value(buffer);

  if (download->resume_support)
  {
    set_pause_button_label(_("Pause"));
    pause_button->show();
    pause_button->activate();
  } else
  {
    pause_button->deactivate();
  }

  gettimeofday(&update_time, NULL);
  this->redraw();
  proz_download_start_downloads(download,  download->resume_mode);
  status = DL_DOWNLOADING;
  return;

}


void DL_Window::unpause_download()
{

  assert(status = DL_PAUSED);

  if (got_info == FALSE)
  {
    dl_start(4, do_ftpsearch);
    return;
  }

  if (got_info == TRUE && got_dl == FALSE)
  {
    /*setup the download */
    download = proz_download_init(&connection->u);
    proz_download_set_msg_proc(download, ms, this);
      download->resume_mode = TRUE;
    start_download();
    return;
  }
}


void DL_Window::pause_download()
{

  /*TODO: Check and see if download is not resumable dont pause */
  if (status == DL_DOWNLOADING)
  {
    proz_download_stop_downloads(download);

  } else if (status == DL_GETTING_INFO)
  {
    /*terminate info thread */
    pthread_cancel(info_thread);
    pthread_join(info_thread, NULL);
  }
  set_pause_button_label(_("Run"));
  this->redraw();
  status = DL_PAUSED;
}




void DL_Window::handle_info_thread()
{
  char buffer[MAX_MSG_SIZE];

  if (message_gui->running == TRUE)
  {
    if (message_gui->ok_button_pressed == TRUE)
    {
      message_gui->win->hide();
      message_gui->running = FALSE;
      got_info = FALSE;
      status = DL_IDLING;
      cleanup(FALSE);
      return;
    } else
      return;
  }

  bool getting_info =proz_connection_running(connection);


  if (getting_info == FALSE)
  {
    browser->add(_("Waiting till all threads terminate"));
    pthread_join(info_thread, NULL);
    browser->add(_("Thread ended"));

    if (connection->err == HOK || connection->err == FTPOK)
    {
      got_info = TRUE;
      url_box->value(connection->u.url);
      this->label(strdup(connection->u.url));

      browser->add(_("Got info succesfully"));
      if (connection->main_file_size != -1)
      {
	sprintf(buffer, _("File Size: %lld Kb"),
		connection->main_file_size / 1024);
	progress_box->show();
      } else
	sprintf(buffer, _("File Size is UNKOWN"));
      file_size_box->value(buffer);

      //TODO CHANGED by me
      if (connection->main_file_size != -1 && do_ftpsearch == TRUE)
      {
	status = DL_FTPSEARCHING;
	ftpsearch_win->show();
	if(rt.ftpsearch_server_id==0)
	  {
	  ftpsearch_win->fetch_mirror_info(&connection->u, connection->main_file_size, "http://www.filesearching.com/cgi-bin/s", FILESEARCH_RU, rt.ftps_mirror_req_n);
	  }
	else	  if(rt.ftpsearch_server_id==1)
	  {
	  ftpsearch_win->fetch_mirror_info(&connection->u, connection->main_file_size, "http://ftpsearch.itb.ac.id/", LYCOS, rt.ftps_mirror_req_n);
	  }
	else	  if(rt.ftpsearch_server_id==2)
	  {
	  ftpsearch_win->fetch_mirror_info(&connection->u, connection->main_file_size, "http://www.searchftps.com/indexer/search.aspx", LYCOS, rt.ftps_mirror_req_n);
	  }
      }
      else
	{
	  do_download();
	}

    } else
    {

      if (connection->err == FTPNSFOD || connection->err == HTTPNSFOD)
      {
	char buffer[MAX_MSG_SIZE];
	snprintf(buffer, MAX_MSG_SIZE, _("The URL %s doesnt exist!"),
		 connection->u.url);
	message_gui->set_label(buffer);
	message_gui->win->show();
	message_gui_type = DLG_URLNSFOD;
	message_gui->running = TRUE;

      } else
      {
	message_gui->set_label(proz_strerror(connection->err));
	message_gui->win->show();
	message_gui_type = DLG_UNKNOWNERR;
	message_gui->running = TRUE;
      }

    }
  }
}


void DL_Window::handle_ftpsearch()
{

  uerr_t err;
  err = ftpsearch_win->callback();
  if (err == MASSPINGDONE)
  {
    if (ftpsearch_win->request->num_mirrors == 0)
    {
      browser->
	  add(_
	      ("No suitable mirrors were found, downloading from original server"));
      using_ftpsearch = FALSE;
      // status = DL_IDLING;
      ftpsearch_win->hide();
      do_download();
      return;
    }
    using_ftpsearch = TRUE;
    //   status = DL_IDLING;
    ftpsearch_win->exit_ftpsearch_button->hide();
    do_download();
    return;
  }
  if (err == FTPSFAIL)
  {

    using_ftpsearch = FALSE;
    //    status = DL_IDLING;
    do_download();
    return;
  }

  if(ftpsearch_win->exit_ftpsearch_button_pressed==TRUE)
    {
      if(ftpsearch_win->got_mirror_info ==TRUE)
	{
	  using_ftpsearch = TRUE;
	}
      else
	{
	  using_ftpsearch = FALSE;
	}
      do_download();
    }
}

void DL_Window::handle_download_thread()
{

  char buf[1000];
  uerr_t err;
  struct timeval cur_time;
  struct timeval diff_time;

    err = proz_download_handle_threads(download);
 

  gettimeofday(&cur_time, NULL);

  proz_timeval_subtract(&diff_time, &cur_time, &update_time);

  if ((((diff_time.tv_sec * 1000) + (diff_time.tv_usec / 1000)) > 200)
      || err == DLDONE)
  {
    for (int i = 0; i < download->num_connections; i++)
    {

      sprintf(buf, "%d         %10s          %15s      %10Ld", i + 1,
	      download->pconnections[i]->u.host,
	      proz_connection_get_status_string(download->pconnections[i]),
	      proz_connection_get_total_bytes_got(download->
						  pconnections[i]));
      fls[i]->value(buf);
    }

    sprintf(buf, _("Total Bytes Received: %Ld Kb"),
	    proz_download_get_total_bytes_got(download) / 1024);

    bytes_recv_box->value(buf);

    sprintf(buf, _("Average Speed: %.3f Kb/sec"),
	    proz_download_get_average_speed(download) / 1024);
    dl_speed_box->value(buf);

    int secs_left;

    if ((secs_left = proz_download_get_est_time_left(download)) != -1)
    {
      if (secs_left < 60)
	sprintf(buf, _("Download Time: %d seconds"), secs_left);
      else if (secs_left < 3600)
	sprintf(buf, _("Download Time: %d minutes %d seconds"), secs_left / 60,
		secs_left % 60);
      else
	sprintf(buf, _("Download Time: %d hours %d minutes"), secs_left / 3600,
		(secs_left % 3600) / 60);
      est_time_box->show();
      est_time_box->value(buf);
    }

    if (download->main_file_size != -1)
    {
      //    progress_box->value(50.0);
      progress_box->
	  value((((double) proz_download_get_total_bytes_got(download) /
		  download->main_file_size) * 100));
    }

    /*The time of the current screen */
    gettimeofday(&update_time, NULL);
  }

  if (err == DLDONE)
  {
    char *label = (char *) malloc(PATH_MAX + 40);
    /*Wait till all are completed */
    browser->add(_("Waiting till all threads terminate"));
    /* Now set the progress abr to 100% */

    progress_box->value(100);

    browser->add(_("Got download succesfully, now building file"));
    got_dl = TRUE;

    /* TODO Should we close the main window here or disable just the buttons */
    resume_later_button->hide();
    no_resume_later_button->hide();
    pause_button->hide();
    snprintf(label, PATH_MAX + 40, _("Building file %s"),
	     download->u.file);
    join_gui->set_box_label(label);
    /*TODO add a function to set he wins label */
    join_gui->win->label(label);
    join_gui->win->redraw();
    join_gui->progress_box->show();
    join_gui->running = TRUE;
    join_gui->win->show();

    //       free(label);
    status = DL_JOINING;
    proz_download_join_downloads(download);
    joining_thread_running = TRUE;
  }

  if (err == CANTRESUME)
  {
    /*FIXME Free the conections array and the download struct */
    browser->
	add
	(_
	 ("Error the server/proxy lied about resuming so I have to restart this from the beginning!"));

    for (int i = 0; i < num_connections; i++)
    {
      scroll_win->remove(fls[i]);
      delete(fls[i]);
    }
    /*We can only use one connections and we cant resume */
    num_connections = 1;
    connection->resume_support = FALSE;
    got_dl = FALSE;
    status = DL_RESTARTING;
  }

  if (err == DLLOCALFATAL)
  {

    char buffer[MAX_MSG_SIZE];
    snprintf(buffer, MAX_MSG_SIZE,
	     _
	     ("One connection of the download %s encountered a unrecoverable local error, usually lack of free space, or a write to bad medium, or a problem with permissions,so please fix this and retry"),
	     connection->u.url);
    message_gui->set_label(buffer);
    message_gui->win->show();
    message_gui_type = DLG_ABORT;
    message_gui->running = TRUE;
    got_dl = FALSE;
    status = DL_FATALERR;
  }


  if (err == DLREMOTEFATAL)
  {

    char buffer[MAX_MSG_SIZE];
    snprintf(buffer, MAX_MSG_SIZE,
	     _
	     ("A connection(s) of the download %s encountered a unrecoverable remote error, usually the file not being present in the remote server, therefore the download had to be aborted!"),
	     connection->u.url);
    message_gui->set_label(buffer);
    message_gui->win->show();
    message_gui_type = DLG_ABORT;
    message_gui->running = TRUE;
    got_dl = FALSE;
    status = DL_FATALERR;
  }

}


void DL_Window::handle_joining_thread()
{

  uerr_t building_status = proz_download_get_join_status(download);

  if (building_status == JOININPROGRESS)
  {
  
    join_gui->progress_box->value(proz_download_get_file_build_percentage(download));

    /*has the user pressed cancel */
    if (join_gui->button_pressed == 1)
    {
      /*End the joining thread */
      proz_download_cancel_joining_thread(download);
      joining_thread_running = FALSE;
      status = DL_IDLING;
      /*Close the window */
      join_gui->win->hide();
      join_gui->running = FALSE;
      this->hide();
      ftpsearch_win->hide();
    }
    join_gui->win->redraw();
  }

  if (building_status == JOINERR)
  {
    if (joining_thread_running == TRUE)
    {
      proz_download_wait_till_end_joining_thread(download);
      joining_thread_running = FALSE;
      join_gui->win->show();
      join_gui->set_box_label(download->file_build_msg);
      join_gui->set_button_label(_("Close"));
      join_gui->win->redraw();
    }
    /*has the user pressed OK at the end of the download */
    if (join_gui->button_pressed == 1)
    {
      proz_download_free_download(download, 0);
      /*TODO ugly kludge below */
      status = DL_IDLING;
      /*Close the window */
      join_gui->win->hide();
      join_gui->running = FALSE;
      this->hide();
       ftpsearch_win->hide();
       
    }
  }

  if (building_status == JOINDONE)
  {

    if (joining_thread_running == TRUE)
    {
      proz_download_wait_till_end_joining_thread(download);
      joining_thread_running = FALSE;
      join_gui->progress_box->value(100.0);
      join_gui->set_box_label(download->file_build_msg);
      join_gui->set_box_label(_("All Done"));
      join_gui->set_button_label(_("Close"));
      join_gui->win->redraw();

    }
    /*has the user pressed OK at the end of the download */
    if (join_gui->button_pressed == 1)
    {
      proz_download_delete_dl_file(download);
      proz_download_free_download(download, 0);
      /*TODO ugly kludge below */
      status = DL_IDLING;
      /*Close the window */
      join_gui->win->hide();
      join_gui->running = FALSE;
      this->hide();
      ftpsearch_win->hide();
    }
  }
}


void DL_Window::handle_dl_fatal_error()
{

  if (message_gui->running == TRUE)
  {
    if (message_gui->ok_button_pressed == TRUE)
    {
      message_gui->win->hide();
      message_gui->running = FALSE;
      status=DL_FATALERR;
      cleanup(FALSE);
      return;
    } else
      return;
  }
}



void DL_Window::display_message(const char *msg)
{
  browser->add(msg, 0);

  if (browser->size() > 0)
  {
    browser->middleline(browser->size());
  }
}




void DL_Window::draw()
{

  Fl_Window::draw();
}


/*Callback for the button that appears in the joining dialog  */
void cb_join_jbutton(Fl_Button * button, void *data)
{
  dl_join_gui *dgui = (dl_join_gui *) data;
  dgui->button_pressed = TRUE;
}


/*Callback for the button that appears in the joining dialog  */
void cb_dlwin_no_resume_later(Fl_Button * button, void *data)
{
  DL_Window *dl_window = (DL_Window *) data;
  dl_window->cleanup(TRUE);
  dl_window->status=DL_ABORTED;	
}


/*Callback for the button that appears in the joining dialog  */
void cb_dlwin_resume_later(Fl_Button * button, void *data)
{
  DL_Window *dl_window = (DL_Window *) data;
  dl_window->cleanup(FALSE);
  dl_window->status=DL_ABORTED;
}

/*Callback for the pause button  */
void cb_dlwin_pause(Fl_Button * button, void *data)
{
  DL_Window *dl_window = (DL_Window *) data;

  //TODO look carefully here *'
  if (dl_window->status != DL_PAUSED)
  {
    dl_window->pause_download();
    return;
  } else if (dl_window->status == DL_PAUSED)
  {
    dl_window->unpause_download();
    return;
  }
}




/*Callback for the button that appears in the message dialog  */
void cb_message_ok_button(Fl_Button * button, void *data)
{
  flproz_message *gui = (flproz_message *) data;
  gui->ok_button_pressed = TRUE;
}


/*Callback for the button that appears in the message dialog  */
void cb_ask_yes_button(Fl_Button * button, void *data)
{
  flproz_ask *gui = (flproz_ask *) data;
  gui->yes_button_pressed = TRUE;
}

/*Callback for the button that appears in the message dialog  */
void cb_ask_no_button(Fl_Button * button, void *data)
{
  flproz_ask *gui = (flproz_ask *) data;
  gui->no_button_pressed = TRUE;
}
