/******************************************************************************
 fltk prozilla - a front end for prozilla, a download accelerator library
 Copyright (C) 2001 Kalum Somaratna

 FLTK PROZGUI - a GUI download accelerator
 Copyright (C) 2011 Raviyanto Ahmad

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
******************************************************************************/

#ifndef dl_win_h
#define dl_win_h
#include <FL/Fl.H>
#include "Fl_Progress.H"
#include "prozilla.h"
#include <FL/Fl_Window.H>
extern void cb_dl_window(Fl_Window*, void*);
#include <FL/Fl_Button.H>
extern void cb_dlwin_resume_later(Fl_Button*, void*);
extern void cb_dlwin_pause(Fl_Button*, void*);
extern void cb_dlwin_no_resume_later(Fl_Button*, void*);
#include <FL/Fl_Output.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Scroll.H>

class dl_gui : public Fl_Window {
public:
  dl_gui();
  Fl_Window *dl_win;
  Fl_Button *resume_later_button;
  Fl_Button *pause_button;
  Fl_Button *no_resume_later_button;
  Fl_Output *url_box;
  Fl_Output *resume_status_box;
  Fl_Output *file_size_box;
  Fl_Output *bytes_recv_box;
  Fl_Browser *browser;
  Fl_Output *dl_speed_box;
  Fl_Output *est_time_box;
  Fl_Scroll *scroll_win;
  Fl_Progress * progress_box;
  char pause_button_label[100];
  void set_pause_button_label(char *label);
};
extern void cb_join_jbutton(Fl_Button*, void*);
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

class dl_join_gui {
public:
  dl_join_gui();
  Fl_Window *win;
  Fl_Button *join_button;
  Fl_Box *out_join_box;
  int running;
  Fl_Progress * progress_box;
  int button_pressed;
  char box_label[MAX_MSG_SIZE];
  char button_label[100];
  void set_box_label(char *label);
  void set_button_label(char *label);
};
extern void cb_message_ok_button(Fl_Button*, void*);

class flproz_message {
public:
  flproz_message();
  Fl_Window *win;
  Fl_Button *ok_button;
  Fl_Box *out_msg_box;
  int running;
  int ok_button_pressed;
  char buffer[MAX_MSG_SIZE];
  void set_label(char *label);
};
extern void cb_ask_yes_button(Fl_Button*, void*);
extern void cb_ask_no_button(Fl_Button*, void*);

class flproz_ask {
public:
  flproz_ask();
  Fl_Window *win;
  Fl_Button *yes_button;
  Fl_Button *no_button;
  Fl_Box *out_msg_box;
  int yes_button_pressed;
  char buffer[MAX_MSG_SIZE];
  int no_button_pressed;
  void set_label(char *label);
  int running;
};

class flproz_choice {
public:
  flproz_choice();
  Fl_Window *win;
  Fl_Button *button1;
  Fl_Button *button2;
  Fl_Box *out_msg_box;
  int button1_pressed;
  char buffer[MAX_MSG_SIZE];
  int button2_pressed;
  char button1_label[100];
  char button2_label[100];
  void set_label(char *label);
  void set_button1_label(char *label);
  void set_button2_label(char *label);
  int running;
};
#endif
