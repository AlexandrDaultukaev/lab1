.PHONY: all clean

all: bin/geometry bin/geometry-test format 

bin/geometry: build/src/main.o build/src/func.o
	gcc -Wall -Werror build/src/main.o build/src/func.o -o bin/geometry -lm

bin/geometry-test: build/test/main.o build/test/geometry_test.o build/src/func.o
	gcc -Wall -Werror build/test/main.o build/test/geometry_test.o build/src/func.o -o bin/geometry-test -lm

build/src/main.o: src/main.c src/main.h
	gcc -Wall -Werror -I src -c src/main.c -o build/src/main.o -lm

build/src/func.o: src/func.c src/main.h
	gcc -Wall -Werror -I src -c src/func.c -o build/src/func.o -lm

format: src/main.c src/main.h src/func.c
	clang-format -i src/main.c src/func.c src/main.h test/geometry_test.c test/main.c

build/test/main.o: thirdparty/ctest.h
	gcc -I thirdparty -c test/main.c -o build/test/main.o -lm

build/test/geometry_test.o: src/main.h thirdparty/ctest.h
	gcc -I thirdparty -I src -c test/geometry_test.c -o build/test/geometry_test.o -lm

clean:
	rm -rf  build/test/geometry_test.o bin/geometry bin/geometry-test build/src/func.o build/src/main.o build/test/main.o