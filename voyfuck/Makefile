include ../Makefile.in

BIN=voy

BIN2=bc2voy


.PHONY: all clean test

all: $(BIN) $(BIN2)

$(BIN): main.o
	$(CXX) -o $(BIN) main.o -L$(LIB) -lbfengine

$(BIN2): main2.o
	$(CXX) -o $(BIN2) main2.o -L$(LIB) -lbfengine

main.o: main.cpp config.hpp ../include/main.hpp ../include/bfengine.hpp ../include/help.hpp

main2.o: main2.cpp ../include/main2.hpp ../include/bfengine.hpp ../include/common.hpp \
 config.hpp

clean:
	rm -rf *.exe *.o *.eso $(BIN) $(BIN2)

