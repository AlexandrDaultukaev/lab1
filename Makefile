.PHONY: all clean

all: circle

build/main.o: src/main.c src/main.h
	gcc -Wall -Werror -c src/main.c -o build/main.o -lm

build/func.o: src/main.h src/func.c
	gcc -Wall -Werror -c src/func.c -o build/func.o -lm

circle: build/main.o build/func.o
	gcc -Wall -Werror build/main.o build/func.o -o circle -lm

clean: 
	rm -rf build/*.o circle