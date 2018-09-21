include ../Makefile.in

BIN=bfvm


.PHONY: all clean

all: $(BIN)

$(BIN): main.o
	$(CXX) -o $(BIN) main.o


main.o: main.cpp config.hpp  ../include/bfengine.hpp ../include/help.hpp

clean:
	rm -rf *.exe *.o $(BIN)
