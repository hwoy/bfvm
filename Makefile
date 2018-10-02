.PHONY: all clean bfvm brainfuck voyfuck  \
aSSfuck  Ook!  \
Alphuck reversefuck Blub test_Blub \
Roadrunner  Triplet  uncensoredfuck

all:  bfvm brainfuck voyfuck  aSSfuck  Ook! Alphuck reversefuck Blub Roadrunner Triplet uncensoredfuck


bfvm: 
	make -C bfvm

brainfuck: 
	make -C brainfuck

voyfuck: 
	make -C voyfuck

aSSfuck: 
	make -C aSSfuck

Ook!: 
	make -C Ook!


Alphuck: 
	make -C Alphuck

reversefuck: 
	make -C reversefuck

Blub: 
	make -C Blub

Roadrunner: 
	make -C Roadrunner

Triplet: 
	make -C Triplet

uncensoredfuck: 
	make -C uncensoredfuck

clean:
	make -C bfvm clean ; make -C brainfuck clean ;\
	make -C voyfuck clean ; make -C aSSfuck clean ;\
	make -C Ook! clean ; make -C Alphuck clean ;\
	make -C reversefuck clean ; make -C Blub clean ; make -C Roadrunner clean ; make -C Triplet clean ; \
	make -C uncensoredfuck clean
	

