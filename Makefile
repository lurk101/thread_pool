CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-O3
LDFLAGS=
LDLIBS=

SRCS=main.cpp ThreadPool.h
OBJS=main.o
EXE=pool

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS) $(LDLIBS)

main.o: main.cpp ThreadPool.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(EXE)
