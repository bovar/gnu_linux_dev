all: prog liba libso
	cc prog.o -o prog-a -L. -loutput_static
	cc prog.o -o prog-so -L. -loutput

prog: const.o fun.o prog.o
	cc const.o fun.o prog.o -o prog

liba: const.o fun.o
	ar -rcs liboutput_static.a const.o fun.o

libso: const.o fun.o
	gcc -shared -o liboutput.so const.o fun.o

%.o:	%.c
	cc $< -fPIC -c -o $@

clean:
	rm -f *.o *.so *.a prog prog-a prog-so test_*

test: test0 test1 test2
	cmp test_0 test_0_static
	cmp test_0 test_0_dyn
	echo TEST_1_PASSED

	cmp test_1 test_1_static
	cmp test_1 test_1_dyn
	echo TEST_2_PASSED

	cmp test_2 test_2_static
	cmp test_2 test_2_dyn
	echo TEST_3_PASSED

test0:
	./prog > test_0 2>&1
	./prog-a > test_0_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so > test_0_dyn 2>&1

test1:
	./prog 1 > test_1 2>&1
	./prog-a 1 > test_1_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so 1 > test_1_dyn 2>&1

test2:
	./prog 1 2 3 > test_2 2>&1
	./prog-a 1 2 3 > test_2_static 2>&1
	LD_LIBRARY_PATH=. ./prog-so 1 2 3 > test_2_dyn 2>&1
