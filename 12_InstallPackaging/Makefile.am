RU = ru/LC_MESSAGES

pkgdata_DATA = $(RU)/$(PACKAGE).mo

AM_CFLAGS = -I$(top_builddir)/src
LDADD = $(top_builddir)/src/libroman.la

bin_PROGRAMS=guesser

@DX_RULES@

all-local:	doxygen-doc

doxygen-doc/man/man1/guesser.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/guesser.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

$(RU)/$(PACKAGE).mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

$(PACKAGE).pot: guesser.c
	xgettext -k_ -c $< -o $@

ru.po: $(PACKAGE).pot
	msgmerge -U $@ $<

clean:
	git clean -fd

SUBDIRS = src tests

checklog: check
	cat tests/*.log

gcov: check
	$(MAKE) $(MAKEFLAGS) -C src gcov

http: doxygen-doc
	python3 -m http.server --directory $</html
