CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3
LDFLAGS=
LDLIBS=

SRCS=main.cpp ThreadPool.h
OBJS=main.o

all: example

example: $(OBJS)
	$(CXX) $(LDFLAGS) -o example $(OBJS) $(LDLIBS)

main.o: main.cpp ThreadPool.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) example
