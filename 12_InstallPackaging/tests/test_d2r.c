#include "defs.h"
#include <string.h>

int main() {
	volatile int count_pass = 0;
	volatile int count_fail = 0;
	TEST("10 to Raman", !strcmp(d2r(10), "X"));	
	TEST("69 to Roman", !strcmp(d2r(69), "LXIX"));	
	TEST("23 to Roman", !strcmp(d2r(23), "XXIII"));	
	TEST("88 to Roman", !strcmp(d2r(88), "LXXXVIII"));	
}
