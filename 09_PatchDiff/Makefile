all: main.c main1.c main2.c main3.c
	gcc -Wall -Wextra main.c -o lab0
	gcc -Wall -Wextra main1.c -o lab1
	gcc -Wall -Wextra main2.c -o lab2
	gcc -Wall -Wextra main3.c -o lab3

run: all
	./lab0
	./lab1 10
	./lab2 " @" 8
	./lab3 2 " @" 11
	./lab3 2 " @" 11
	./lab3 1 " @" 11

main1.c: main.c patch1.patch
	cp main.c main1.c
	patch main1.c < patch1.patch

main2.c: main1.c patch2.patch
	cp main1.c main2.c
	patch main2.c < patch2.patch

main3.c: main2.c patch3.patch
	cp main2.c main3.c
	patch main3.c < patch3.patch

clean:
	rm main1.c main2.c main3.c lab0 lab1 lab2 lab3
