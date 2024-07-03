CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3 -flto -ffunction-sections -fdata-sections
LDFLAGS=-O1 -Wl,--gc-sections -Wl,--strip-all
LDLIBS=

OBJS=threads.o getnumproc.o
EXE=threads

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)

threads.o: threads.cpp ThreadPool.hpp getnumproc.h

getnumproc.o: getnumproc.c getnumproc.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
