NAME = gen-expr
SRCS = gen-expr.c
include $(NEMU_HOME)/scripts/build.mk

run:
	rm /tmp/input
	gcc gen-expr.c  -o gen-expr.o
	./gen-expr.o 10000 > /tmp/input
