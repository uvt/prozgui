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

#ifndef FTPSEARCH_WIN_H
#define FTPSEARCH_WIN_H

#include <config.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>	// Fl_Group header file
#include <FL/fl_ask.H>		// FLTK convenience functions
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

#include <FL/Fl_Browser.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Scroll.H>
#include "prozilla.h"
#include "ftps_win.h"



class FTPS_Window:public ftps_gui {
public:
  FTPS_Window();
  void fetch_mirror_info(urlinfo *u, long long file_size, const char *ftps_loc,
			 ftpsearch_server_type_t server_type,
			 int num_req_mirrors);

  void cleanup();

  uerr_t callback();
  void ping_list();

  ftps_request_t *request;

  boolean request_running;
  boolean ping_running;
  boolean got_mirror_info;
  boolean ping_done;
  boolean exit_ftpsearch_button_pressed;

private:
  //   ftp_mirror_t *arranged_mirrors;


};

#endif
