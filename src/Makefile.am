#------------------------------------------------------------------------------
# Process this file with automake to produce Makefile.in.
#------------------------------------------------------------------------------

bin_PROGRAMS    = prozgui

AM_CPPFLAGS = -DLOCALEDIR=\"$(datadir)/locale\"

prozgui_SOURCES = main.cpp download_win.cpp  Fl_Progress.cxx we.cxx init.cpp options.cpp dl_win.cxx prefs.cpp ftps_win.cxx ftpsearch_win.cpp savefile.cpp
INCLUDES        = -I. -I..  -I../libprozgui/src -I@includedir@ 
AM_CFLAGS          = @CFLAGS@ -D_REENTRANT -Wall -ggdb
AM_CFLAGS         += -DGLOBAL_CONF_FILE="\"@sysconfdir@/prozgui.conf\"" -DLOCALEDIR=\"$(datadir)/locale\"
AM_LDFLAGS		= @LDFLAGS@ 
LDADD           = ../libprozgui/src/libprozgui.la  -L@libdir@  -L/usr/X11R6/lib  -lfltk 
LIBS            = @LIBS@ $(THREAD_LIBS) 
