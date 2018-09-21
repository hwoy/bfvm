.PHONY: all clean bfengin brainfuck voyfuck test_voyfuck assfuck test_assfuck Ook! test_Ook! Alphuck test_Alphuck

all: bfengin brainfuck voyfuck  assfuck  Ook! Alphuck

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

Ook!:
	make -C Ook!
test_Ook!:
	make -C Ook! test

Alphuck:
	make -C Alphuck
test_Alphuck:
	make -C Alphuck test

clean:
	make -C bfengine clean ; make -C brainfuck clean ; make -C voyfuck clean ; make -C assfuck clean ; make -C Ook! clean ; make -C Alphuck clean

test: test_voyfuck test_assfuck test_Ook! test_Alphuck
