GREEN=\\033[0;32m
RESET=\\e[0m
.PHONY: all clean test

all: prog prog-a prog-so test

prog: const.o fun.o prog.o
	cc const.o fun.o prog.o -o prog

prog-a: prog.o liboutput_static.a
	cc prog.o -o prog-a -L. -loutput_static

prog-so: prog.o liboutput.so
	cc prog.o -o prog-so -L. -loutput

liboutput_static.a: const.o fun.o
	ar -rcs liboutput_static.a const.o fun.o

liboutput.so: const.o fun.o
	gcc -shared -o liboutput.so const.o fun.o

%.o:	%.c outlib.h
	cc $< -fPIC -c -o $@

clean:
	rm -f *.o *.so *.a prog prog-a prog-so test_*

test: test0 test1 test2

test0:
	@echo -----RUNNING_TEST_1-----
	./prog > test_0 2>&1
	./prog-a > test_0_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so > test_0_dyn 2>&1
	cmp test_0 test_0_static
	cmp test_0 test_0_dyn
	@echo "${GREEN}-----TEST_1_PASSED-----${RESET}\n"

test1:
	@echo -----RUNNING_TEST_2-----
	./prog 1 > test_1 2>&1
	./prog-a 1 > test_1_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so 1 > test_1_dyn 2>&1
	cmp test_1 test_1_static
	cmp test_1 test_1_dyn
	@echo "${GREEN}-----TEST_2_PASSED-----${RESET}\n"


test2:
	@echo -----RUNNING_TEST_3-----
	./prog 1 2 3 > test_2 2>&1
	./prog-a 1 2 3 > test_2_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so 1 2 3 > test_2_dyn 2>&1
	cmp test_2 test_2_static
	cmp test_2 test_2_dyn
	@echo "${GREEN}-----TEST_3_PASSED-----${RESET}"


