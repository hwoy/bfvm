.PHONY: all clean bfengin brainfuck voy

all: bfengin brainfuck voy

bfengin:
	make -C bfengine

brainfuck:
	make -C brainfuck

voy:
	make -C voy

clean:
	make -C bfengine clean ; make -C brainfuck clean ; make -C voy clean
