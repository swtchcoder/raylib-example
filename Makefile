GCC:=gcc
SRC:=$(shell find src -type f -path "*.c")
CFLAGS:=-Wall -lraylib 

UNAME:=$(shell uname -s)
ifeq (${UNAME}, Windows_NT)
	CFLAGS+=-lgdi32 -lwinmm
else
	CFLAGS+=-lGL -lm -lpthread -ldl -lrt -lX11
endif

build: ${SRC}
	if [ ! -d "bin" ]; then mkdir bin; fi
	${GCC} -o bin/executable ${SRC} ${CFLAGS}

run: build
	bin/*
