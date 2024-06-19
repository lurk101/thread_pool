CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3
LDFLAGS=
LDLIBS=

OBJS=test.o getnumproc.o
EXE=test

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)

test.o: test.cpp ThreadPool.hpp getnumproc.hpp

getnumproc.o: getnumproc.cpp getnumproc.hpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
