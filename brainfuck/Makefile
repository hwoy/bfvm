include ../Makefile.in

BIN=bf


.PHONY: all clean

all: $(BIN)

$(BIN): main.o
	$(CXX) -o $(BIN) main.o -L$(LIB) -lbfengine


main.o: main.cpp config.hpp ../include/main.hpp ../include/bfengine.hpp ../include/help.hpp

clean:
	rm -rf *.exe *.o $(BIN)
