.PHONY: all clean bfengine brainfuck voyfuck test_voyfuck \
assfuck test_assfuck Ook! test_Ook! \
Alphuck test_Alphuck reversefuck test_reversefuck Blub test_Blub \
Roadrunner test_Roadrunner Triplet test_Triplet

all: bfengine brainfuck voyfuck  assfuck  Ook! Alphuck reversefuck Blub Roadrunner Triplet

bfengine:
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

reversefuck:
	make -C reversefuck
test_reversefuck:
	make -C reversefuck test

Blub:
	make -C Blub
test_Blub:
	make -C Blub test

Roadrunner:
	make -C Roadrunner
test_Roadrunner:
	make -C Roadrunner test

Triplet:
	make -C Triplet
test_Triplet:
	make -C Triplet test

clean:
	make -C bfengine clean ; make -C brainfuck clean ;\
	make -C voyfuck clean ; make -C assfuck clean ;\
	make -C Ook! clean ; make -C Alphuck clean ;\
	make -C reversefuck clean ; make -C Blub clean ; make -C Roadrunner clean ; make -C Triplet clean

test: bfengine test_voyfuck test_assfuck test_Ook! test_Alphuck test_reversefuck test_Blub test_Roadrunner test_Triplet
