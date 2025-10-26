#include <string.h>
#include <dlfcn.h>

int remove(const char *f) {
	if (strstr(f, "PROTECT")) {
		return 0;
	}

	int (* std_remove)(const char *);

	std_remove = dlsym(RTLD_NEXT, "remove");
	if (!std_remove) {
		return 1;
	}

	return std_remove(f);
}	
