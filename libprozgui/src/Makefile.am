#------------------------------------------------------------------------------
# Process this file with automake to produce Makefile.in.
#------------------------------------------------------------------------------

lib_LTLIBRARIES = libprozgui.la

libprozgui_la_SOURCES = \
common.h \
connect.c connect.h \
connection.c connection.h \
debug.c debug.h \
download.c download.h \
ftp.c ftp.h \
ftpparse.c ftpparse.h \
main.c \
misc.c misc.h \
netrc.c netrc.h \
prozilla.h \
url.c url.h\
http.c http.h\
http-retr.c http-retr.h\
ftp-retr.c ftp-retr.h\
logfile.c logfile.h\
ftpsearch.c ftpsearch.h\
ping.c ping.h

# 0:0:0
# 0 -> interface version, changes whenever you change the API
# 0 -> changes whenever you make a revision of an interface no
#      API changes...
# 0 -> changes whenever you change the API but keep it backwards
#      compatible (have not removed a function from the API, for
#      example...)
libprozgui_la_LDFLAGS = -version-info 1:0:1

includedir = $(prefix)/include
include_HEADERS = prozilla.h netrc.h common.h
AM_CPPFLAGS = -DLOCALEDIR=\"$(datadir)/locale\" -ggdb 
LIBS            = @LIBS@ $(THREAD_LIBS)
