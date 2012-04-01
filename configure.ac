#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([baka], [0.0.0], [allan@archlinux.org], [], [https://github.com/allanbrokeit/baka])
AC_CONFIG_SRCDIR([src/baka.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.11.1 foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AM_PATH_GLIB_2_0([2.28.8],,[AC_MSG_ERROR([glib 2.28.8 or higher is required.])], [gmodule])
AM_PATH_GTK_3_0([3.0.11],,AC_MSG_ERROR([Gtk+ 3.0.11 or higher is required.]))

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.


# Allow running program from source directory
AC_ARG_ENABLE(run-in-source-tree,
              AC_HELP_STRING([--enable-run-in-source-tree],[enable searching for UI files in local directory]),
              [AC_DEFINE(BAKA_RUN_IN_SOURCE_TREE, 1, [enable searching for UI files in local directory])],
              [])


AC_CONFIG_FILES([Makefile
                 data/Makefile
                 src/Makefile])
AC_OUTPUT
