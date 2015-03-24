CC=g++
CFLAGS=

ifeq ($(OS),Windows_NT)
	EXT=.exe
else
	EXT=
endif

.PHONY: all test clean

all: test

test: test.cpp complex.cpp complex.h
	$(CC) $^ -o /tmp/$@$(EXT)

clean:
	rm -f test$(EXT)
