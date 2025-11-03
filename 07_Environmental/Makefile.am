CC=cc
CFLAGS=-Wall
bin_PROGRAMS=rhasher
rhasher_SOURCES=rhasher.c

test:
	@echo "-----Running_TEST1-----"
	echo 'Md5 "aaa' | ./rhasher | tail -n 1 > test1.txt
	echo -n 'aaa' | md5sum | cut -d ' ' -f 1 > test1_answ.txt
	@cmp test1.txt test1_answ.txt
	@echo "-----Test1_passed-----"
	
	@echo "-----Running_TEST2-----"
	echo 'Sha1 "aaa' | ./rhasher | tail -n 1 > test2.txt
	echo -n 'aaa' | sha1sum | cut -d ' ' -f 1  > test2_answ.txt
	@cmp test2.txt test2_answ.txt
	@echo "-----Test2_passed-----"
