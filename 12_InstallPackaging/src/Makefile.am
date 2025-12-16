CFLAGS = -std=c99 -Wall -Wextra -ansi

RU = ru/LC_MESSAGES

pkgdata_DATA = $(RU)/$(PACKAGE).mo

if COND_GCOV
CFLAGS += -O0 -g -fprofile-arcs -ftest-coverage
else
CFLAGS  += -O3 -g3
endif

lib_LTLIBRARIES = libroman.la
libroman_la_LDFLAGS = -version-info 1:0:0
bin_PROGRAMS = guesser

guesser_LDADD = libroman.la

libroman.c: roman.h

$(RU)/$(PACKAGE).mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

$(PACKAGE).pot: guesser.c
	xgettext -k_ -c $< -o $@

ru.po: $(PACKAGE).pot
	msgmerge -U $@ $<

gcov:
	gcov -o .libs libroman -t -k -b | egrep -v '[[:digit:]]:[ /][*]'
