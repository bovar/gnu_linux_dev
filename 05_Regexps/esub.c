#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Too few arguements\n");
        printf("Usage: ./esub <regexp> <substitution> <string>\n");
        exit(1);
    }

    regex_t regex;
    regmatch_t *bags;

    int status = regcomp(&regex, argv[1], REG_EXTENDED);

    if (status)
    {
        char buf[1024];
        regerror(status, &regex, buf, sizeof(buf));
        printf("%s\n", buf);
        exit(1);
    }

    bags = calloc(regex.re_nsub + 1, sizeof(regmatch_t));

    if (!regexec(&regex, argv[3], regex.re_nsub + 1, bags, 0))
    {
        int b = bags[0].rm_so, e = bags[0].rm_eo;

        int slen = strlen(argv[2]);
        char *subst_res = calloc(slen, sizeof(char));
        int size_res = slen;
        
        int i = 0;
        int j = 0;
        while (i < slen) {
            if (argv[2][i] == '\\' && i < slen - 1 && isdigit(argv[2][i + 1])) {
                int bl = bags[argv[2][i + 1] - '0'].rm_so, el = bags[argv[2][i + 1] - '0'].rm_eo;
                for (int k = bl; k < el; ++k) {
                    if (j == size_res - 1) {
                        subst_res = realloc(subst_res, size_res * 2);
                    }
                    subst_res[j] = argv[3][k];
                    ++j;
                }
		++i;
            } else {
                if (j == size_res - 1) {
                    subst_res = realloc(subst_res, size_res * 2);
                }
                subst_res[j] = argv[2][i];
                ++j;
            }
            ++i;
        }
	subst_res[j] = '\0';

        printf("%.*s%s%s\n", b, argv[3], subst_res, argv[3] + e);
        free(subst_res);
    }

    free(bags);
    regfree(&regex);
}
