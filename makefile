SRCS = $(filter-out src/main.c, $(wildcard src/*.c))

all:
	gcc -std=gnu11 ./src/main.c -Iinclude ${SRCS} -o ./build/pcli

clean:
	rm ./build/pcli

run:
	./build/pcli

.PHONY: all