tshell: main.o my_system.o
	gcc -o tshell main.o my_system.o

main.o: main.c my_system.h
	gcc -g -c main.c

my_system.o : my_system.c
	gcc -g -c my_system.c


