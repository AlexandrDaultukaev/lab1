.PHONY: all clean

all: circle

main.o: main.c main.h
	gcc -Wall -Werror -c main.c -lm

func.o: main.h func.c
	gcc -Wall -Werror -c func.c -lm

circle: main.o func.o
	gcc -Wall -Werror main.o func.o -o circle -lm

clean: 
	rm -rf *.o circle