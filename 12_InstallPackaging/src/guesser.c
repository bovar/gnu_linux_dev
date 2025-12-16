/** @mainpage Guesser program
 * 
 * This is program that guess your number between 1 and 100.
 * 
 * The main() function asks you to chose the number and then guesses it asks if your number is greater then something.
 * 
 * You can run program in Roman number mode just pass -r. 
 * 
 */

/** @page Guesser program
 * This is program that guess your number between 1 and 100.
 * 
 * Argument --help Show help info
 * Argument -r run roman numbers mode
 *
 */

#include "config.h"
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman.h"

/** @file guesser.c
 * Implementation
 */

#define _(STRING) gettext(STRING)



/** Guessing number between 1 and 100
 * Options:
 * --help help
 * -r Set -r to use roman numbers
 */
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALE_PATH);
	textdomain(PACKAGE);

	int is_roman = 0;
	if (argc == 2) {
		if (!strcmp(argv[1], "-r")) {
			is_roman = 1;
		} else if (!strcmp(argv[1], "--help")) {
			printf(_("Usage ./guesser [options]\n"));
			printf(_("Options:\n"));
			printf(_("\t-r\tUse Roman numbers.\n"));
			printf(_("\t--help\tDisplay this information.\n"));
			return 0;
		}
	}
	if (is_roman) {
		printf(_("Guess the number from I to C\n"));
	} else {
		printf(_("Guess the number from 1 to 100\n"));
	}

	int l = 1, r = 100;
	while (r - l > 1) {
		char buf[50];
		if (is_roman) {
			printf(_("Is your number greater than %s? (yes/no)\n"), d2r((l + r) / 2));
		} else {
			printf(_("Is your number greater than %d? (yes/no)\n"), (l + r) / 2);
		}
		if (scanf("%s", buf) == 0) {
			exit(1);
		}
		if (!strcmp(buf, _("yes"))) {
			l = (l + r) / 2;
		} else if (!strcmp(buf, _("no"))) {
			r = (l + r) / 2;
		} else {
			fprintf(stderr, _("Wrong answer. Say \"yes\" or \"no\"\n"));
		}
	}
	if (is_roman) {
		printf(_("Your number is %s\n"), d2r(r));
	} else {
		printf(_("Your number is %d\n"), r);
	}
}
