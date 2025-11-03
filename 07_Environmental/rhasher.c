#include "rhash.h" /* LibRHash interface */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <config.h>

#ifdef READLN
#include <readline/readline.h>
#endif

void string_to_lower(char *str) {
	for (ssize_t i = 0; i < strlen(str); ++i) {
		str[i] = tolower(str[i]);
	}
}

int get_method(const char *str){
	if (!strcmp(str, "sha1")) {
		return RHASH_SHA1;
	}
	if (!strcmp(str, "md5")) {
		return RHASH_MD5;
	}
	if (!strcmp(str, "tth")) {
		return RHASH_TTH;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	unsigned char digest[64];
	char output[130];

	char *input = NULL;
	const char delim[] = " ";
	rhash_library_init(); /* initialize static data */

#ifndef READLN
	size_t len;
	while (getline(&input, &len, stdin) != -1) {
#else
	while ((input = readline(NULL)) != NULL) {
#endif
		char *newline_ptr = strchr(input, '\n');

		if (newline_ptr != NULL) {
			*newline_ptr = '\0';
		}

		char *tok = strtok(input, delim);
		int out = isupper(tok[0]) ? RHPR_HEX : RHPR_BASE64;
		string_to_lower(tok);
		
		int method = get_method(tok);
		if (method == -1) {
			fprintf(stderr, "No such method\n");
			continue;
		}

		tok = strtok(NULL, delim);
		int res;
			
		if (tok[0] == '\"') {
			res = rhash_msg(method, tok + 1, strlen(tok) - 1, digest);
		} else {
			res = rhash_file(method, tok, digest);
		}

		if (res < 0) {
			fprintf(stderr, "message digest calculation error\n");
			continue;
		}
		rhash_print_bytes(output, digest, rhash_get_digest_size(method),
				out);

		printf("%s\n", output);
	}

	if (input != NULL)
		free(input);
	return 0;
}
