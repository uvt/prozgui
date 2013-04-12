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

#ifndef ftps_win_h
#define ftps_win_h
#include <FL/Fl.H>
#include "prozilla.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Return_Button.H>
extern void cb_exit_ftpsearch(Fl_Return_Button*, void*);
#include <FL/Fl_Box.H>

class ftps_gui : public Fl_Window {
public:
  ftps_gui();
  Fl_Window *ftps_win;
  Fl_Output *ftps_file_box;
  Fl_Browser *mirror_browser;
  Fl_Return_Button *exit_ftpsearch_button;
  Fl_Browser *message_browser;
};
#endif
