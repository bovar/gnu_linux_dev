CFLAGS = -std=c99 -Wall -Wextra -ansi

if COND_GCOV
CFLAGS += -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS  += -O3 -g3
endif

lib_LTLIBRARIES = libroman.la
libroman_la_LDFLAGS = -version-info 1:0:0
bin_PROGRAMS = guesser

guesser_LDADD = libroman.la
AM_CFLAGS=-D'LOCALE_PATH="$(localedir)"'


libroman.c: roman.h

gcov:
	gcov -o .libs libroman -t -k -b | egrep -v '[[:digit:]]:[ /][*]'
