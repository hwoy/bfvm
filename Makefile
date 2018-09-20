.PHONY: all clean bfengin brainfuck

all: bfengin brainfuck

bfengin:
	make -C bfengine

brainfuck:
	make -C brainfuck

clean:
	make -C bfengine clean ; make -C brainfuck clean
