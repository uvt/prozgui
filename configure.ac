AC_PREREQ([2.67])
AC_INIT([prozgui],[2.0.7])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.11.1])
AC_CONFIG_MACRO_DIR([m4])
AC_LANG([C++])
AC_SEARCH_LIBS([strerror],[cposix])     

AC_CONFIG_SUBDIRS([libprozgui])

AC_ARG_WITH(fltk-libs, [  --with-fltk-libs        set directory for FLTK library],
    LDFLAGS="-L$withval $LDFLAGS",)

AC_ARG_WITH(fltk-includes, [  --with-fltk-includes    set directory for FLTK includes],
    CFLAGS="-I$withval $CFLAGS"
    CXXFLAGS="-I$withval $CXXFLAGS",)


dnl LDLIBS="-lX11 -lXext -lm"
AC_CANONICAL_HOST

dnl ---------------------------------------------------------------------------
dnl Checks for programs.
dnl ---------------------------------------------------------------------------
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
LT_INIT
AC_CHECK_PROG(UNAME,uname,uname,:)
AC_ENABLE_STATIC([])
AC_DISABLE_SHARED([])

dnl -------------
dnl gettext stuff
dnl -------------
PACKAGE=gettext
VERSION=0.18.1
AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE")
AC_DEFINE_UNQUOTED(VERSION, "$VERSION")
AC_SUBST(PACKAGE)
AC_SUBST(VERSION)
AC_C_INLINE
AM_INIT_AUTOMAKE(gettext, 0.18.1)
ALL_LINGUAS="en"

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.18.1])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_TIME
AC_STRUCT_TM

dnl Check for libraries...
dnl LDFLAGS="${LDFLAGS:=}"
dnl AC_SUBST(LDFLAGS)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([libintl.h limits.h malloc.h stdlib.h string.h sys/time.h strcasecmp strncasecmp unistd.h SYS/types.h])

dnl Checks for string functions.
AC_CHECK_FUNCS([getcwd gettimeofday memset mkdir setlocale strdup strerror])
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_HEADER_STDBOOL
AC_PROG_AWK
AC_PROG_LN_S 
AC_PROG_MAKE_SET
m4_pattern_allow

dnl ---------------------------------------------------------------------------
dnl Checks for libraries.
dnl ---------------------------------------------------------------------------
AC_TYPE_SIZE_T
TYPE_SOCKLEN_T

dnl ==============
dnl CHECK FLTK LIB
dnl ==============
AC_CHECK_HEADERS(FL/Fl.H, have_fltk=yes, have_fltk=no)

dnl AC_SUBST(FLTK_LIBS)
dnl AC_SUBST(FLTK_DIR)
    
dnl Check for GUI libraries...
OLDLIBS="$LIBS"


AC_PATH_X

  if test "$x_libraries" = "/usr/lib"; then
        echo "Ignoring X library directory \"$x_libraries\" requested by configure."
        x_libraries="NONE"
    fi

    if test ! "$x_libraries" = "NONE" -a ! "$x_libraries" = ""; then
        LDFLAGS="$LDFLAGS -L$x_libraries"
        if test "$uname" = "SunOS"; then
                LDFLAGS="$LDFLAGS -R$x_libraries"
        fi
    fi


    if test "$x_includes" = "/usr/include"; then
        echo "Ignoring X include directory \"$x_includes\" requested by configure."
        x_includes="NONE"
    fi

    if test ! "$x_includes" = "NONE" -a ! "$x_includes" = ""; then
        CFLAGS="$CFLAGS -I$x_includes"
        CXXFLAGS="$CXXFLAGS -I$x_includes"
    fi


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

AC_CHECK_LIB(m,pow)

AC_CHECK_LIB(X11,XOpenDisplay)
AC_CHECK_LIB(Xext,XdbeQueryExtension)
			
AC_CHECK_LIB(Xpm,XpmCreatePixmapFromData)
dnl Check FLTK by itself
AC_CHECK_LIB(fltk,numericsort)

   dnl Check FLTK + OpenGL to see if that works...
    if test "$ac_cv_lib_fltk_numericsort" = no; then
        unset ac_cv_lib_fltk_numericsort
        AC_CHECK_LIB(GL,glEnable)
        AC_CHECK_LIB(fltk,numericsort)
    fi

dnl AC_CHECK_LIB(fltk,main)
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

AC_PATH_XTRA
if test "$X_PRE_LIBS" != ""; then
        echo "Ignoring libraries \"$X_PRE_LIBS\" requested by configure."
	fi
	if test "$X_LIBS" = " -L/usr/lib"; then
	        echo "Ignoring X library directory \"$X_LIBS\" requested by
		configure."
		        X_LIBS=""
fi
			

CXXFLAGS="-Wall -ggdb -D_REENTRANT"

AC_DEFINE(_FILE_OFFSET_BITS, [64], [Use 64bit interface for filesystem operations])

dnl Large File Summit support
AC_SYS_LARGEFILE

AC_CONFIG_FILES([Makefile src/Makefile man/Makefile po/Makefile.in])
AC_OUTPUT
