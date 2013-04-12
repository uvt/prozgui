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
#ifndef DOWNLOAD_WIN_H
#define DOWNLOAD_WIN_H

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
#include "dl_win.h"
#include "ftpsearch_win.h"


void ms(const char *msg, void *cb_data);
void info_callback(void *);


typedef enum {
  DL_IDLING,
  DL_GETTING_INFO,
  DL_FTPSEARCHING,
  DL_DLPRESTART,
  DL_DOWNLOADING,
  DL_JOINING,
  DL_RESTARTING,
  DL_PAUSED,
  DL_ABORTED,
  DL_FATALERR,
} dlwin_status_t;


//The running dialog type 
typedef enum {
  DLG_GENERIC,
  DLG_URLNSFOD,
  DLG_TARGETERASE,
  DLG_JOININING,
  DLG_PREVRESUME,
  DLG_ABORT,
  DLG_UNKNOWNERR,
} dlg_class;

class DL_Window:public dl_gui {

  void draw();
  int cx, cy;
  char key;
public:
   DL_Window(urlinfo * url_data, Fl_Boxtype b, int x, int y,
	     const char *l);

  void dl_start(int num_connections, boolean ftpsearch);
  void my_cb();
  void display_message(const char *msg);

  void handle_info_thread();
  void handle_ftpsearch();
  void handle_download_thread();

  void start_download();

  void pause_download();
  void unpause_download();

  void handle_joining_thread();
  void handle_dl_fatal_error();
  void scroll_browser_to_end();
  void cleanup(boolean erase_dlparts);

  Fl_Output **fls;
  dl_join_gui *join_gui;
  flproz_message *message_gui;
  flproz_ask *ask_gui;
  flproz_choice *choice_gui;
  connection_t *connection;
  download_t *download;
  urlinfo u;
  boolean got_info;
  boolean got_dl;

  dlg_class message_gui_type;
  dlg_class choice_gui_type;
  dlg_class ask_gui_type;
  dlg_class join_gui_type;

  dlwin_status_t status;

  pthread_t info_thread;
  pthread_mutex_t getinfo_mutex;
  int num_connections;
  /*The time  elapsed since the last update */
  struct timeval update_time;

private:
  void do_download();
  void handle_prev_download();
  boolean joining_thread_running;
  boolean do_ftpsearch;
  boolean using_ftpsearch;
  FTPS_Window *ftpsearch_win;
};

#endif
