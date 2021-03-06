dnl ***************************************************************************
dnl libprozilla - a download accelerator library
dnl Copyright (C) 2001 Kalum Somaratna
dnl 
dnl libprozgui - a download accelerator library
dnl Copyright (C) 2011 Raviyanto Ahmad
dnl
dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
dnl ***************************************************************************

AC_PREREQ([2.67])
AC_INIT([libprozgui], [1.2.2])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11.1])
AC_DEFINE(_GNU_SOURCE)
AC_LANG_C
AC_CANONICAL_HOST
dnl ---------------------------------------------------------------------------
dnl Checks for programs.
dnl ---------------------------------------------------------------------------

AC_PROG_CC

AC_AIX
AC_ISC_POSIX
AC_MINIX

AC_PROG_CXX
AM_PROG_CC_STDC
AC_PROG_INSTALL
AM_ENABLE_STATIC
AM_DISABLE_SHARED
AC_PROG_LIBTOOL

dnl -------------
dnl gettext stuff
dnl -------------
PACKAGE=gettext
VERSION=0.18.1
AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE")
AC_DEFINE_UNQUOTED(VERSION, "$VERSION")
AC_SUBST(PACKAGE)
AC_SUBST(VERSION)
AM_INIT_AUTOMAKE(gettext, 0.18.1)
ALL_LINGUAS="en"
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.18.1])
dnl ---------------------------------------------------------------------------
dnl Checks for libraries.
dnl ---------------------------------------------------------------------------

case $host in
  *-*-freebsd*)
    THREAD_LIBS="-pthread"
    ;;
 *-*-openbsd*)
    THREAD_LIBS="-pthread"
    ;;
  *)
    AC_CHECK_LIB(pthread, pthread_create,
             THREAD_LIBS="-lpthread",
             AC_MSG_ERROR([** The pthread library is not installed.**]))
    ;;
esac
AC_SUBST(THREAD_LIBS)

# Whenever both -lsocket and -lnsl are needed, it seems to be always the
# case that gethostbyname requires -lnsl.  So, check -lnsl first, for it
# to be in LIBS before the setsockopt checks are performed.  *However*,
# on SINIX-N 5.43, this is false, and gethostent seems to be a better
# candidate. So, let's use it below instead of gethostbyname, and see.

# [ This is ripped from GNU tar. ]

AC_CHECK_FUNC(gethostent)
if test $ac_cv_func_gethostent = no; then
  AC_CHECK_LIB(nsl, gethostent)
fi
AC_CHECK_FUNC(setsockopt)
if test $ac_cv_func_setsockopt = no; then
  AC_CHECK_LIB(socket, setsockopt)
fi

AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_FUNC_REALLOC

dnl ---------------------------------------------------------------------------
dnl Checks for header files.
dnl ---------------------------------------------------------------------------
AC_CHECK_HEADERS([arpa/inet.h fcntl.h libintl.h limits.h locale.h memory.h netdb.h netinet/in.h stdlib.h string.h strings.h sys/socket.h sys/time.h unistd.h])
AC_HEADER_STDC
AC_HEADER_TIME
AC_CHECK_HEADERS(stdio.h stdlib.h unistd.h ctype.h errno.h sys/types.h)
AC_CHECK_HEADERS(sys/stat.h sys/socket.h netinet/in.h arpa/inet.h netdb.h pthread.h)
AC_CHECK_HEADERS(memory.h string.h strings.h time.h sys/time.h pwd.h)
AC_CHECK_HEADERS(fcntl.h assert.h limits.h)


dnl ---------------------------------------------------------------------------
dnl Checks for typedefs, structures, and compiler characteristics.
dnl ---------------------------------------------------------------------------

AC_C_CONST
AC_TYPE_SIZE_T
TYPE_SOCKLEN_T
AC_C_INLINE

dnl See if socket() is found from libsocket

AC_CHECK_LIB(
        [socket],
        [socket],
        [
                LIBS="${LIBS} -lsocket"
                AC_CHECK_LIB(
                        [resolv],
                        [res_query],
                        [LIBS="${LIBS} -lresolv"]
                )
        ]
)

dnl ---------------------------------------------------------------------------
dnl Checks for library functions.
dnl ---------------------------------------------------------------------------
AC_CHECK_FUNCS([gethostbyaddr gettimeofday memchr memset select setlocale socket strcasecmp strchr strdup strerror strncasecmp strrchr strstr uname])
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(select socket strdup strerror strtol strncasecmp)
AC_CHECK_FUNCS(snprintf vsnprintf __snprintf __vsnprintf strchr strrchr)

dnl ---------------------------------------------------------------------------
dnl Handle user-specified --enable-FEATURE options.
dnl ---------------------------------------------------------------------------

AC_ARG_ENABLE(compiler-warnings, [  --enable-compiler-warnings=[no/min/yes]    Issue warnings? (default=no)], , enable_compiler_warnings=no)

dnl ============================================================ NLS Support ===
dnl
dnl AC_CHECK_LIB(intl, gettext,
dnl                [LIBS="$LIBS -lintl"])

  AC_CHECK_FUNC(bindtextdomain,,
    [ AC_CHECK_LIB(intl, bindtextdomain,
        [ LIBS="${LIBS} -lintl"
	    ],
	        [ AC_MSG_ERROR([NLS (national language support) has been requested but
		*** the 'bindtextdomain' function neither has been found in your C runtime library
		*** nor in an external library called 'libintl'.
		***
		*** Install your vendor's version of libintl or get GNU gettext available
		*** from ftp://ftp.gnu.org/pub/gnu/gettext/.
		***])])])


  AC_PATH_PROG(XGETTEXT, xgettext)
  AC_PATH_PROG(MSGMERGE, msgmerge)
  AC_PATH_PROG(MSGFMT, msgfmt)
  
  MSGMERGE="${MSGMERGE}" # --indent --verbose"
  MSGFMT="${MSGFMT}" # --check --statistics --verbose"
  
  if test ! -x "$MSGFMT" ; then
     AC_MSG_ERROR(['msgfmt' not found. Perhaps you need to install 'gettext'?.])
  fi


  AC_SUBST(XGETTEXT)
  AC_SUBST(MSGMERGE)
  AC_SUBST(MSGFMT)

CFLAGS="-Wall -ggdb -D_REENTRANT"

if test "x$GCC" != "xyes"; then
  enable_compiler_warnings = "no";
fi

if test "x$enable_compiler_warnings" != "xno"; then
  if test "x$enable_compiler_warnings" = "xmin"; then
    CFLAGS="$CFLAGS -g -ansi -pedantic"
  fi
  if test "x$enable_compiler_warnings" = "xyes"; then
    CFLAGS="$CFLAGS \
-g -ansi -pedantic -W -Wtraditional -Wshadow -Wpointer-arith \
-Wcast-qual -Wcast-align -Wwrite-strings -Wconversion \
-Waggregate-return -Wstrict-prototypes -Wmissing-prototypes \
-Wmissing-declarations -Wnested-externs -Winline"
  fi
fi

AC_DEFINE(_FILE_OFFSET_BITS, [64], [Use 64bit interface for filesystem operations])

dnl Large File Summit support
AC_SYS_LARGEFILE

AC_CONFIG_FILES(Makefile src/Makefile po/Makefile.in)
AC_OUTPUT
