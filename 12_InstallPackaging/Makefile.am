SUBDIRS = src tests po

@DX_RULES@

all-local:	doxygen-doc

doxygen-doc/man/man1/guesser.c.1:	doxygen-doc

man1_MANS = doxygen-doc/man/man1/guesser.c.1

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

clean:
	git clean -fd


checklog: check
	cat tests/*.log

gcov: check
	$(MAKE) $(MAKEFLAGS) -C src gcov

http: doxygen-doc
	python3 -m http.server --directory $</html
