.PHONY: all clean bfengine bfvm brainfuck voyfuck  \
assfuck  Ook!  \
Alphuck reversefuck Blub test_Blub \
Roadrunner  Triplet  uncensoredfuck

all: bfengine bfvm brainfuck voyfuck  assfuck  Ook! Alphuck reversefuck Blub Roadrunner Triplet uncensoredfuck

bfengine:
	make -C bfengine

bfvm: bfengine
	make -C bfvm

brainfuck: bfengine
	make -C brainfuck

voyfuck: bfengine
	make -C voyfuck

assfuck: bfengine
	make -C assfuck

Ook!: bfengine
	make -C Ook!


Alphuck: bfengine
	make -C Alphuck

reversefuck: bfengine
	make -C reversefuck

Blub: bfengine
	make -C Blub

Roadrunner: bfengine
	make -C Roadrunner

Triplet: bfengine
	make -C Triplet

uncensoredfuck: bfengine
	make -C uncensoredfuck

clean:
	make -C bfengine clean ; make -C bfvm clean ; make -C brainfuck clean ;\
	make -C voyfuck clean ; make -C assfuck clean ;\
	make -C Ook! clean ; make -C Alphuck clean ;\
	make -C reversefuck clean ; make -C Blub clean ; make -C Roadrunner clean ; make -C Triplet clean ; \
	make -C uncensoredfuck clean
	

