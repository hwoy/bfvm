.PHONY: all clean bfengin brainfuck voyfuck assfuck

all: bfengin brainfuck voyfuck test_voyfuck test_assfuck assfuck test 

bfengin:
	make -C bfengine

brainfuck:
	make -C brainfuck

voyfuck:
	make -C voyfuck
test_voyfuck:
	make -C voyfuck test

assfuck:
	make -C assfuck
test_assfuck:
	make -C assfuck test

clean:
	make -C bfengine clean ; make -C brainfuck clean ; make -C voyfuck clean ; make -C assfuck clean

test: test_voyfuck test_assfuck
