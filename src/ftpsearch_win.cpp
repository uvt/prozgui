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
#include <FL/fl_message.H>
#include "main.h"
#include "ftpsearch_win.h"

void ftps_win_message_proc(const char *msg, void *cb_data);



FTPS_Window::FTPS_Window():ftps_gui()
{
  memset(&request, 0, sizeof(request));

  request_running = FALSE;
  ping_running = FALSE;
  got_mirror_info = FALSE;
  exit_ftpsearch_button_pressed = FALSE;
  hide();
}


void FTPS_Window::fetch_mirror_info(urlinfo *u, long long file_size,
				    const char *ftps_loc,
				    ftpsearch_server_type_t server_type,
				    int num_req_mirrors)
{
  assert(u->file);
  ftps_file_box->value(u->file);

  request=proz_ftps_request_init(u, file_size, const_cast<char *>(ftps_loc),
			    server_type, num_req_mirrors);
  proz_connection_set_msg_proc(request->connection, ftps_win_message_proc,
			       this);
  proz_get_complete_mirror_list(request);

  request_running = TRUE;
}


void ftps_win_message_proc(const char *msg, void *cb_data)
{

  FTPS_Window *win = (FTPS_Window *) cb_data;
  win->message_browser->add(msg, 0);

  if (win->message_browser->size() > 0)
    win->message_browser->bottomline(win->message_browser->size());

}

uerr_t FTPS_Window::callback()
{

  if (request_running == TRUE)
  {
    if (proz_request_info_running(request) == FALSE)
    {
      pthread_join(request->info_thread, NULL);
      if (request->err != MIRINFOK)
      {
	message_browser->add("Unable to get mirror info", 0);
	message_browser->add(proz_strerror(request->err));
	request_running = FALSE;
	got_mirror_info = FALSE;
	exit_ftpsearch_button->hide();
	return FTPSFAIL;
      } else
      {
	message_browser->add("got mirror info", 0);
	for (int i = 0; i < request->num_mirrors; i++)
	{
	  mirror_browser->add(request->mirrors[i].server_name);

	}
      }

      request_running = FALSE;
      got_mirror_info = TRUE;

  request->max_simul_pings=rt.max_simul_pings;
  request->ping_timeout.tv_sec=rt.max_ping_wait;
  request->ping_timeout.tv_usec=0;

      /*Launch the pinging thread */
      proz_mass_ping(request);
      ping_running = TRUE;
      return MASSPINGINPROGRESS;
    }
    return FTPSINPROGRESS;
  }

  if (ping_running == TRUE)
  {
    longstring buf;
    for (int i = 0; i < request->num_mirrors; i++)
    {
      pthread_mutex_lock(&request->access_mutex);
      ftp_mirror_stat_t status = request->mirrors[i].status;
      pthread_mutex_unlock(&request->access_mutex);
      switch (status)
      {
      case UNTESTED:
	snprintf(buf, sizeof(longstring), "%s        %20s",
		 request->mirrors[i].server_name, "NOT TESTED");
	break;
      case RESPONSEOK:
	snprintf(buf, sizeof(longstring), "%s        %20dms",
		 request->mirrors[i].server_name,
		 request->mirrors[i].milli_secs);
	break;
      case NORESPONSE:
      case ERROR:
	snprintf(buf, sizeof(longstring), "%s         %20s",
		 request->mirrors[i].server_name, "NO REPONSE");
	break;
      default:
	snprintf(buf, sizeof(longstring), "%s        %20s",
		 request->mirrors[i].server_name, "Unkown condition!!");
	break;
      }
      mirror_browser->text(i + 1, buf);
      // mirror_browser->data(i,strdup(buf));
    }

    if (proz_request_mass_ping_running(request) == FALSE)
    {
      ping_done = TRUE;
      ping_running = FALSE;
      message_browser->add("Ping run completed", 0);
      message_browser->add("Sorting list", 0);
      proz_sort_mirror_list(request->mirrors, request->num_mirrors);

      /* We should have a seprate func to display this */
      for (int i = 0; i < request->num_mirrors; i++)
      {
	pthread_mutex_lock(&request->access_mutex);
	ftp_mirror_stat_t status = request->mirrors[i].status;
	pthread_mutex_unlock(&request->access_mutex);
	switch (status)
	{
	case UNTESTED:
	  snprintf(buf, sizeof(longstring), "%s        %20s",
		   request->mirrors[i].server_name, "NOT TESTED");
	  break;
	case RESPONSEOK:
	  snprintf(buf, sizeof(longstring), "%s        %20dms",
		   request->mirrors[i].server_name,
		   request->mirrors[i].milli_secs);
	  break;
	case NORESPONSE:
	case ERROR:
	  snprintf(buf, sizeof(longstring), "%s        %20s",
		   request->mirrors[i].server_name, "NO REPONSE");
	  break;
	default:
	  snprintf(buf, sizeof(longstring), "%s        %20s",
		   request->mirrors[i].server_name, "Unkown condition!!");
	  break;
	}
	mirror_browser->text(i + 1, buf);

	// mirror_browser->data(i,strdup(buf));
      }
      //      this->redraw();
      return MASSPINGDONE;
    }
    //      this->redraw();
    return MASSPINGINPROGRESS;
  }
  return MASSPINGINPROGRESS;
}



void FTPS_Window::cleanup()
{
  if(request_running==TRUE)
    {
      proz_cancel_mirror_list_request(request);
      return;
    }

 if(ping_running==TRUE)
    {
      proz_cancel_mass_ping(request);
      return;
    }
}


void cb_exit_ftpsearch(Fl_Return_Button *button, void * data)
{

  FTPS_Window *window=(FTPS_Window *) data;

  window->exit_ftpsearch_button_pressed = TRUE;

  if(window->request_running==TRUE)
    {
      proz_cancel_mirror_list_request(window->request);
    }

 if(window->ping_running==TRUE)
    {
      proz_cancel_mass_ping(window->request);
    }
 window->hide();
}
