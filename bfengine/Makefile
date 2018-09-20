include ../Makefile.in

.PHONY: all clean

all: bfengine.o
	ar crv ../lib/libbfengine.a bfengine.o  && cp *.hpp ../include

bfengine.o: bfengine.cpp bfengine.hpp

clean:
	rm -rf *.exe *.o ../lib/*.a
