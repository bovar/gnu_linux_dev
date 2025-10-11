#include <stdio.h>
#include <stdlib.h>

void print_help() {
    printf("Usage:\n");
    printf("  ./range              : Print help message\n");
    printf("  ./range N            : Print numbers from 0 to N-1\n");
    printf("  ./range M N          : Print numbers from M to N-1\n");
    printf("  ./range M N S        : Print numbers from M to N-1 with step S\n");
}

void print_seq(int m, int n, int s) {
    for (int cur = m; cur < n; cur += s) {
	printf("%d\n", cur);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        exit(0);
    }
    
    int m = 0, n, s = 1;
    
    if (argc == 2) {
	n = atoi(argv[1]);
    }

    if (argc > 2) {
	m = atoi(argv[1]);
	n = atoi(argv[2]);

	if (argc == 4) {
	    s = atoi(argv[3]);
	}
    }
    print_seq(m, n, s);
}
