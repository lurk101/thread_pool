CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3
LDFLAGS=
LDLIBS=

OBJS=main.o getnumproc.o
EXE=pool

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)

main.o: main.cpp ThreadPool.h getnumproc.h

getnumproc.o: getnumproc.c getnumproc.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
