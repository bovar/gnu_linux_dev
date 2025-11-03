AC_PREREQ([2.71])
AC_INIT([rhasher], [0.1], [vova.dubkov.2004@mail.ru])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash], [rhash_library_init])

# Checks for header files.
AC_CHECK_HEADERS([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_ARG_WITH([readline],
            [AS_HELP_STRING([--with-readline],
              [enable experimental support for readline])],
            [],
            [with_readline=no])

AS_IF([test "x$with_readline" != xno],
            [AC_CHECK_LIB([readline], [readline],
              [AC_SUBST([rhasher_LDADD], ["-lreadline"])
               AC_DEFINE([READLN], [1],
                         [Define if you have libreadline])
              ],
              [AC_MSG_FAILURE(
                 [--with-readline was given, but test for readline failed])],
              )])

AS_IF([test "x$with_readline" != xno],
    [AC_CHECK_HEADER([readline/readline.h])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
