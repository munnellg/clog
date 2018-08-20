#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

AC_INIT([clog], [1.0], [munnellg@tcd.ie])
AC_CONFIG_SRCDIR([src/clog.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

CLOG_MAJOR_VERSION=1
CLOG_MINOR_VERSION=0
CLOG_MICRO_VERSION=0
CLOG_VERSION=$CLOG_MAJOR_VERSION.$CLOG_MINOR_VERSION.$CLOG_MICRO_VERSION

AC_SUBST(CLOG_MAJOR_VERSION)
AC_SUBST(CLOG_MINOR_VERSION)
AC_SUBST(CLOG_MICRO_VERSION)
AC_SUBST(CLOG_INTERFACE_AGE)
AC_SUBST(CLOG_BINARY_AGE)
AC_SUBST(CLOG_VERSION)

AM_INIT_AUTOMAKE

LT_INIT

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([memory.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([clog.pc
                 Makefile
                 src/Makefile])
AC_OUTPUT
