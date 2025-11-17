RU = ru/LC_MESSAGES

bin_PROGRAMS=main
pkgdata_DATA = $(RU)/$(PACKAGE).mo

$(RU)/$(PACKAGE).mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

$(PACKAGE).pot: main.c
	xgettext -k_ -c $< -o $@

ru.po: $(PACKAGE).pot
	msgmerge -U $@ $<

clean:
	git clean -fd
