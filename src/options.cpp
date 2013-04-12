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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <FL/fl_ask.H>
#include <FL/filename.H>
#include "main.h"
#include "init.h"
#include "options.h"
#include "we.h"
#include "prefs.h"

void pref_panel_setup()
{
  char buf[1000];
  //  sprintf(buf, "%d", rt.num_connections);
  threads_in->value((double) rt.num_connections);

  sprintf(buf, "%d", rt.retry_delay);
  retry_delay_in->value(buf);

  snprintf(buf, 1000, "%d", (int) rt.timeout.tv_sec);
  in_timeout->value(buf);

  in_pasv_button->value(rt.ftp_use_pasv);
  in_no_cache_button->value(rt.http_no_cache);
  in_outputdir->value(rt.output_dir);

  snprintf(buf, 1000, "%.2f", (float) rt.max_bps_per_dl / 1024);
  in_bps_per_dl->value(buf);

  in_http_proxy_host->value(rt.http_proxy->proxy_url.host);
  snprintf(buf, 1000, "%d", rt.http_proxy->proxy_url.port);
  in_http_proxy_port->value(buf);

  in_http_proxy_user->value(rt.http_proxy->username);
  in_http_proxy_passwd->value(rt.http_proxy->passwd);

  in_ftp_proxy_host->value(rt.ftp_proxy->proxy_url.host);
  sprintf(buf, "%d", rt.ftp_proxy->proxy_url.port);
  in_ftp_proxy_port->value(buf);
  in_ftp_proxy_user->value(rt.ftp_proxy->username);
  in_ftp_proxy_passwd->value(rt.ftp_proxy->passwd);
  in_ftp_proxy_type->value(rt.ftp_proxy->type);

  if (rt.use_http_proxy == FALSE && rt.use_ftp_proxy == FALSE)
    {
      in_direct_conn_button->value(1);
      in_use_proxy_button->value(0);
      gr_proxy_grp->deactivate();
    } else
      {
	in_direct_conn_button->value(0);
	in_use_proxy_button->value(1);
	gr_proxy_grp->activate();
      }
  // sprintf(buf, "%d", rt.http_proxy->proxy_url.port);

  rt.use_http_proxy ==
    TRUE ? in_use_http_proxy->value(1) : in_use_http_proxy->value(0);
  rt.use_ftp_proxy ==
    TRUE ? in_use_ftp_proxy->value(1) : in_use_ftp_proxy->value(0);


  rt.use_ftpsearch==TRUE?in_use_ftpsearch_button->value(1):in_use_ftpsearch_button->value(0);
;
  mirrors_in->value((double) rt.ftps_mirror_req_n);
  snprintf(buf, 1000, "%d", (int) rt.max_ping_wait);
  in_ping_timeout->value(buf);

  in_simul_pings->value((double) rt.max_simul_pings);

  ftps_server_choice->value(rt.ftpsearch_server_id);
}


int pref_panel_set_values()
{
  char *url_str;
  urlinfo url_data;
  uerr_t err;

  //FIXME do a check here before setting value
  rt.num_connections = (int) threads_in->value();
  rt.retry_delay = atoi(retry_delay_in->value());

  rt.timeout.tv_sec = atoi(in_timeout->value());
  rt.timeout.tv_usec = 0;

  rt.max_bps_per_dl = (long) (atof(in_bps_per_dl->value()) * 1024);

  if (rt.max_bps_per_dl < 0)
  {
    rt.max_bps_per_dl = 0;
  }

  rt.ftp_use_pasv = in_pasv_button->value();
  rt.http_no_cache = in_no_cache_button->value();

  char *abs_out_dir = (char *) malloc(PATH_MAX);
  fl_filename_expand(abs_out_dir, in_outputdir->value());
  fl_filename_absolute(abs_out_dir, abs_out_dir);

  //  filename_absolute(abs_out_dir, in_outputdir->value());
  /*Check and see whether the directory is valid */
  if (fl_filename_isdir(abs_out_dir) == 0)
  {
    fl_message(_("%s does not seem to be a valid directory"), abs_out_dir);
    free(abs_out_dir);
    return 0;
  } else
  {
    free(rt.output_dir);
    rt.output_dir = strdup(abs_out_dir);
    /*FIXME currently rt._dl_dir == rt.output_dir */
    free(rt.dl_dir);
    rt.dl_dir = strdup(abs_out_dir);
  }
  free(abs_out_dir);

  url_str =
      (char *) malloc(strlen(in_http_proxy_host->value()) + 1 +
		      strlen(in_http_proxy_port->value()) + 1);

  sprintf(url_str, "%s:%s", in_http_proxy_host->value(),
	  in_http_proxy_port->value());

  err = proz_parse_url(url_str, &url_data, 0);
  if (err != URLOK)
  {
    fl_message(_("%s does not seem to be a valid HTTP proxy value"),
	       url_str);
    return 0;
  }

  proz_free_url(&rt.http_proxy->proxy_url, 0);
  free(url_str);
  memcpy(&rt.http_proxy->proxy_url, &url_data, sizeof(url_data));


  /*copy the http proxy username and password */
  free(rt.http_proxy->username);
  rt.http_proxy->username = strdup(in_http_proxy_user->value());
  free(rt.http_proxy->passwd);
  rt.http_proxy->passwd = strdup(in_http_proxy_passwd->value());

  rt.use_http_proxy = in_use_http_proxy->value() == 1 ? TRUE : FALSE;

  url_str =
      (char *) malloc(strlen(in_ftp_proxy_host->value()) + 1 +
		      strlen(in_ftp_proxy_port->value()) + 1);

  sprintf(url_str, "%s:%s", in_ftp_proxy_host->value(),
	  in_ftp_proxy_port->value());

  err = proz_parse_url(url_str, &url_data, 0);
  if (err != URLOK)
  {
    fl_message(_("%s does not seem to be a valid FTP proxy value"),
	       url_str);
    return 0;
  }
  memcpy(&rt.ftp_proxy->proxy_url, &url_data, sizeof(url_data));

  free(url_str);

  /*copy the ftp proxy username and password */
  free(rt.ftp_proxy->username);
  rt.ftp_proxy->username = strdup(in_ftp_proxy_user->value());
  free(rt.ftp_proxy->passwd);
  rt.ftp_proxy->passwd = strdup(in_ftp_proxy_passwd->value());
  rt.ftp_proxy->type = (proxy_type) in_ftp_proxy_type->value();
  rt.use_ftp_proxy = in_use_ftp_proxy->value() == 1 ? TRUE : FALSE;


  rt.ftps_mirror_req_n =(int) mirrors_in->value();
  rt.max_simul_pings = (int) in_simul_pings->value();
  rt.max_ping_wait =  atoi(in_ping_timeout->value());

  if(rt.max_ping_wait >120)
    rt.max_ping_wait=120;
  if(rt.max_ping_wait <0)
    rt.max_ping_wait=1;

  in_use_ftpsearch_button->value()==1?rt.use_ftpsearch=TRUE:rt.use_ftpsearch=FALSE;

  rt.ftpsearch_server_id = ftps_server_choice->value();
  /*Set the values necessary for libprozgui */
  set_runtime_values();
  return 1;
}

void cb_prefs_ok(Fl_Button *, void *)
{
  if (pref_panel_set_values() == 1)
    rt.prefs_win->hide();
  save_prefs();
}


void cb_prefs_cancel(Fl_Button *, void *)
{
  rt.prefs_win->hide();
}


void cb_prefs_tab(Fl_Tabs * tabs, void *)
{

}


void cb_prefs_conn(Fl_Check_Button * button, void *)
{
  if (button->value() == 1)
  {
    in_use_http_proxy->value(0);
    in_use_ftp_proxy->value(0);
    gr_proxy_grp->deactivate();
  }

}

void cb_prefs_use_proxy(Fl_Check_Button * button, void *)
{

  if (button->value() == 1)
  {
    gr_proxy_grp->activate();
  }
}


void cb_about_ok(Fl_Button * button, void *)
{
  win_about->hide();
}
