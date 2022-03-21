NAME = gen-expr
SRCS = gen-expr.c
include $(NEMU_HOME)/scripts/build.mk

run:
	gcc gen-expr.c  -o gen-expr.o
	./gen-expr.o 100000 > /tmp/input
