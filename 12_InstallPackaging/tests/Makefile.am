TESTS_ENVIRONMENT = CK_VERBOSITY=$(CK_VERBOSITY)

TESTS = test_d2r test_r2d
check_PROGRAMS = test_d2r test_r2d

AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libroman.la @CHECK_LIBS@
