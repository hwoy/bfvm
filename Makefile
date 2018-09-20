.PHONY: all clean bfengin brainfuck voy assfuck

all: bfengin brainfuck voy assfuck

bfengin:
	make -C bfengine

brainfuck:
	make -C brainfuck

voy:
	make -C voy

assfuck:
	make -C assfuck

clean:
	make -C bfengine clean ; make -C brainfuck clean ; make -C voy clean ; make -C assfuck clean
