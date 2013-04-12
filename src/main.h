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
#ifndef MAIN_H
#define MAIN_H

#include <sys/time.h>
#include <FL/Fl_Window.H>
#include "prozilla.h"

/* Standard gettext macros. */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#define _(String) gettext(String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif

/* Gettext */


/*We will have a runtime structure for this program */

#define PRZCONFDIR ".prozgui"

struct runtime {
  int num_connections;
  int max_redirections;
  /*
   * whether to use the netrc file 
   */
  int use_netrc;
  int ftp_use_pasv;
  int max_attempts;
  int retry_delay;		/*delay in seconds */
  /*
   * The timeout period for the connections 
   */
  struct timeval timeout;
  int debug_mode;
  int ftp_search;
  int force_mode;
  /* The maximum number of servers to ping at once */
  int max_simul_pings;
  /* The max number of seconds to wait for a server response to ping */
  int max_ping_wait;
  /* The maximum number of servers/mirrors to request */
  int ftps_mirror_req_n;
  long max_bps_per_dl;
  /* The dir to save the generated file in */
  char *output_dir;
  /*The directory where the Dl'ed portions are stored */
  char *dl_dir;
  char *logfile_dir;
  char *home_dir;
  /*The dir where the config files are stored */
  char *config_dir;
  Fl_Window *prefs_win;
  proxy_info *ftp_proxy;
  proxy_info *http_proxy;
  int use_http_proxy;
  int use_ftp_proxy;
  int http_no_cache;
  int use_ftpsearch;
  int ftpsearch_server_id;
};

extern struct runtime rt;

#endif
