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

main.o: main.cpp ThreadPool.hpp getnumproc.hpp

getnumproc.o: getnumproc.cpp getnumproc.hpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
