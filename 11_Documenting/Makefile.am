RU = ru/LC_MESSAGES

bin_PROGRAMS=guesser
pkgdata_DATA = $(RU)/$(PACKAGE).mo

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

http:	doxygen-doc
	python3 -m http.server --directory $</html

clean:
	git clean -fd
