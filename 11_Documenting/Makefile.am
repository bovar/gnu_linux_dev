RU = ru/LC_MESSAGES

bin_PROGRAMS=guesser
pkgdata_DATA = $(RU)/$(PACKAGE).mo

@DX_RULES@

all-local:	doxygen-doc

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
