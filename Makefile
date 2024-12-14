GCC:=gcc
SRC:=$(shell find src -type f -path "*.c")
CFLAGS:=-Wall -lraylib -lgdi32 -lwinmm


build: ${SRC}
	-mkdir bin
	${GCC} -o bin/executable ${SRC} ${CFLAGS}

run: build
	bin/*
