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

#ifndef we_h
#define we_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
extern Fl_Window *win_prefs;
#include <FL/Fl_Tabs.H>
extern void cb_prefs_tab(Fl_Tabs*, void*);
extern Fl_Tabs *tb_prefs;
#include <FL/Fl_Group.H>
extern Fl_Group *gr_prefs_general;
#include <FL/Fl_Input.H>
extern Fl_Input *retry_delay_in;
#include <FL/Fl_Counter.H>
extern Fl_Counter *threads_in;
#include <FL/Fl_Box.H>
extern Fl_Input *in_timeout;
#include <FL/Fl_Check_Button.H>
extern Fl_Check_Button *in_pasv_button;
extern Fl_Check_Button *in_no_cache_button;
extern Fl_Input *in_outputdir;
extern Fl_Input *in_bps_per_dl;
extern Fl_Group *gr_prefs_proxy;
extern Fl_Group *gr_proxy_grp;
extern Fl_Input *in_http_proxy_host;
extern Fl_Input *in_http_proxy_port;
extern Fl_Input *in_http_proxy_user;
extern Fl_Input *in_http_proxy_passwd;
extern Fl_Input *in_ftp_proxy_host;
extern Fl_Input *in_ftp_proxy_port;
extern Fl_Input *in_ftp_proxy_user;
extern Fl_Input *in_ftp_proxy_passwd;
#include <FL/Fl_Choice.H>
extern Fl_Choice *in_ftp_proxy_type;
extern Fl_Check_Button *in_use_http_proxy;
extern Fl_Check_Button *in_use_ftp_proxy;
extern void cb_prefs_conn(Fl_Check_Button*, void*);
extern Fl_Check_Button *in_direct_conn_button;
extern void cb_prefs_use_proxy(Fl_Check_Button*, void*);
extern Fl_Check_Button *in_use_proxy_button;
extern Fl_Group *gr_prefs_ftpsearch;
extern Fl_Counter *mirrors_in;
extern Fl_Input *in_ping_timeout;
extern Fl_Counter *in_simul_pings;
extern Fl_Check_Button *in_use_ftpsearch_button;
extern Fl_Choice *ftps_server_choice;
#include <FL/Fl_Button.H>
extern void cb_prefs_ok(Fl_Button*, void*);
extern Fl_Button *ok_button;
extern void cb_prefs_cancel(Fl_Button*, void*);
extern Fl_Button *cancel_button;
Fl_Window* make_prefs_win();
extern Fl_Menu_Item menu_in_ftp_proxy_type[];
extern Fl_Menu_Item menu_ftps_server_choice[];
extern Fl_Window *win_about;
extern void cb_about_ok(Fl_Button*, void*);
#include <FL/Fl_Scroll.H>
Fl_Window* make_about_win();
#include <FL/Fl_Return_Button.H>
extern void cb_url_input_ok(Fl_Return_Button*, void*);
extern Fl_Return_Button *url_input_ok_button;
extern Fl_Input *in_url;
extern void cb_url_input_cancel(Fl_Button*, void*);
extern Fl_Check_Button *do_ftpsearch_button;
Fl_Window* make_url_input_win();
#endif
