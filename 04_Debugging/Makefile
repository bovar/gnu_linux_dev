GREEN=\\033[0;32m
RESET=\\e[0m
.PHONY: all clean test

all: range.c
	cc -Wall -O0 -g range.c -o range

test:
	@echo -----running_test_1-----
	gdb --batch --quiet -x script1.gdb ./range | grep @@@ | sed 's/^....//' > output_1.txt
	cmp output_1.txt answer_1.txt
	@echo "${GREEN}-----test_1_passed-----${RESET}\n"

	@echo -----running_test_2-----
	gdb --batch --quiet -x script2.gdb ./range | grep @@@ | sed 's/^....//' > output_2.txt
	cmp output_2.txt answer_2.txt
	@echo "${GREEN}-----test_2_passed-----${RESET}\n"



clean:
	rm -f range output_1.txt output_2.txt
