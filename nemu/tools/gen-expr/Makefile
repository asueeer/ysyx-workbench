NAME = gen-expr
SRCS = gen-expr.c
include $(NEMU_HOME)/scripts/build.mk

run:
	gcc gen-expr.c  -o gen-expr.o
	./gen-expr.o 1000 > /tmp/input
