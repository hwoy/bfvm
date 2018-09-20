.PHONY: all clean bfengin brainfuck voy assfuck

all: bfengin brainfuck voy test_voy test_assfuck assfuck test 

bfengin:
	make -C bfengine

brainfuck:
	make -C brainfuck

voy:
	make -C voy
test_voy:
	make -C voy test

assfuck:
	make -C assfuck
test_assfuck:
	make -C assfuck test

clean:
	make -C bfengine clean ; make -C brainfuck clean ; make -C voy clean ; make -C assfuck clean

test: test_voy test_assfuck
