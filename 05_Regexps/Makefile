GREEN=\\033[0;32m
RESET=\\e[0m

all: esub

esub: esub.c

test: esub
	@echo -----running_test_1-----
	./esub 'ab' 'BA' 'eabc' > esub.txt
	echo 'eabc' | sed -E 's/ab/BA/' > sed.txt
	cmp esub.txt sed.txt
	@echo "${GREEN}-----test_1_passed-----${RESET}\n"

	@echo -----running_test_2-----
	./esub 'a(b)c' '\1_\1' 'DabcE' > esub.txt
	echo 'DabcE' | sed -E 's/a(b)c/\1_\1/' > sed.txt
	cmp esub.txt sed.txt
	@echo "${GREEN}-----test_2_passed-----${RESET}\n"

	@echo -----running_test_3-----
	./esub '(a)b(c)d(e)' '\3\2\1' '_abcdef_' > esub.txt
	echo '_abcdef_' | sed -E 's/(a)b(c)d(e)/\3\2\1/' > sed.txt
	cmp esub.txt sed.txt
	@echo "${GREEN}-----test_3_passed-----${RESET}\n"

	@echo -----running_test_4-----
	./esub "([[:digit:]]{4}) +([[:digit:]]{1,2}) +([[:alpha:]]+) +([[:alpha:]]+)" "\4, \2 \3 year of \1" "2024 17 October Thursday" > esub.txt 
	echo "2024 17 October Thursday" | sed -E "s/([[:digit:]]{4}) +([[:digit:]]{1,2}) +([[:alpha:]]+) +([[:alpha:]]+)/\4, \2 \3 year of \1/" > sed.txt
	cmp esub.txt sed.txt
	@echo "${GREEN}-----test_4_passed-----${RESET}\n"

clean:
	rm -rf esub esub.txt sed.txt
