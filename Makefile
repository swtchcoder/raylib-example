GCC:=gcc
SRC:=$(shell find src -type f -path "*.c")
CFLAGS:=-Wall -lraylib 

UNAME:=$(shell uname -s)
ifeq (${UNAME}, Linux)
	CFLAGS+=-lGL -lm -lpthread -ldl -lrt -lX11
else
	CFLAGS+=-lgdi32 -lwinmm
endif

build: ${SRC}
	-mkdir bin
	${GCC} -o bin/executable ${SRC} ${CFLAGS}

run: build
	bin/*
