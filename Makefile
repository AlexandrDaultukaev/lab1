main.o: main.c main.h
	gcc -c main.c

func.o: main.h func.c
	gcc -c func.c
	
circle: main.o func.o
	gcc -Wall -Werror main.o func.o -o circle
