#include "defs.h"
#include <string.h>

int main() {
	volatile int count_pass = 0;
	volatile int count_fail = 0;
	TEST("Roman X to arabic", r2d("X") == 10);	
	TEST("Roman LXIX to arabic", r2d("LXIX") == 69);	
	TEST("Roman XXIII to arabic", r2d("XXIII") == 23);	
	TEST("Roman LXXXVIII to arabic", r2d("LXXXVIII") == 88);	
}
