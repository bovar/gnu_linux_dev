GREEN=\\033[0;32m
RESET=\\e[0m

all: move my_remove.so

move: move.c
	cc -O0 move.c -o move

my_remove.so: my_remove.c
	cc -O0 my_remove.c -D_GNU_SOURCE -fPIC -shared -o my_remove.so

test: all
	# Creating input file
	dd if=/dev/urandom of=in.txt bs=1K count=1 >  /dev/null 2>&1
	
	@echo -----RUNNING_TEST_1-----
	strace -o /dev/null -e fault=openat -P in.txt ./move in.txt out.txt 2> /dev/null ; [ $$? -eq  2 ]
	@[ -f in.txt ]	
	@echo "${GREEN}-----TEST_1_PASSED-----${RESET}\n"
	
	@echo -----RUNNING_TEST_2-----
	strace -o /dev/null -e fault=openat -P out.txt ./move in.txt out.txt 2> /dev/null ; [ $$? -eq  3 ]
	@[ -f in.txt ]	
	@echo "${GREEN}-----TEST_2_PASSED-----${RESET}\n"
	
	@echo -----RUNNING_TEST_3-----
	strace -o /dev/null -e fault=write:when=1 ./move in.txt out.txt 2> /dev/null ; [ $$? -eq  4 ]
	@[ -f in.txt ]	
	@echo "${GREEN}-----TEST_3_PASSED-----${RESET}\n"
	
	@echo -----RUNNING_TEST_4-----
	strace -o /dev/null -e fault=read -P in.txt ./move in.txt out.txt 2> /dev/null ; [ $$? -eq  5 ]
	@[ -f in.txt ]	
	@echo "${GREEN}-----TEST_4_PASSED-----${RESET}\n"
	
	@echo -----RUNNING_TEST_5-----
	strace -o /dev/null -e fault=unlink: -P in.txt ./move in.txt out.txt 2> /dev/null ; [ $$? -eq  6 ]
	@[ -f in.txt ]	
	@echo "${GREEN}-----TEST_5_PASSED-----${RESET}\n"
	
	@echo -----RUNNING_TEST_6-----
	dd if=/dev/urandom of=in_PROTECT.txt bs=1K count=1 >  /dev/null 2>&1
	LD_PRELOAD=./my_remove.so ./move in_PROTECT.txt out.txt > /dev/null 2>&1; [ $$? -eq 0 ]
	@[ -f in_PROTECT.txt ]
	@echo "${GREEN}-----TEST_6_PASSED-----${RESET}\n"

clean:
	rm -rf *.txt move my_remove.so
