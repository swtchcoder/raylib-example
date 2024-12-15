NAME=executable
VERSION=0.0.0
CC=gcc

ifeq (${OS},)
	OS=${shell uname -s}
endif

ifeq (${PROCESSOR_ARCHITECTURE},)
	PROCESSOR_ARCHITECTURE= ${shell uname -m}
endif

CFLAGS:=-Wall -lraylib
SRC:=$(wildcard src/*.c)
OUT:=bin/${NAME}-${VERSION}-${OS}-${PROCESSOR_ARCHITECTURE}

ifeq (${OS}, Linux)
	CFLAGS+=-lGL -lm -lpthread -ldl -lrt -lX11
else ifeq (${OS}, Windows_NT)
	CFLAGS+=-lgdi32 -lwinmm
	OUT:=${OUT}.exe
endif


build: ${SRC}	
	@echo ${OS} ${shell uname -p}
	-mkdir bin
	${CC} -o ${OUT} ${SRC} ${CFLAGS}

run: build
	bin/*
