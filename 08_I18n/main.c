#include "config.h"
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#define _(STRING) gettext(STRING)
#define LOCALPATH "."

int main() {
  setlocale(LC_ALL, "");
  bindtextdomain(PACKAGE, LOCALPATH);
  textdomain(PACKAGE);
  printf(_("Guess the number from 1 to 100\n"));

  int l = 1, r = 100;
  while (r - l > 1) {
    char buf[50];
    printf(_("Is your number greater than %d? (yes/no)\n"), (l + r) / 2);
    scanf("%s", buf);
    if (!strcmp(buf, _("yes"))) {
      l = (l + r) / 2;
    } else if (!strcmp(buf, _("no"))) {
      r = (l + r) / 2;
    } else {
      fprintf(stderr, _("Wrong answer. Say \"yes\" or \"no\"\n"));
    }
  }
  printf(_("Your number is %d\n"), r);
}
