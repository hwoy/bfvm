# Brain fuck virtual machine

The virtual machine for trivial brainfuck-cloned semantic programming language.
This project contains virtual machine, basic libryries for brainfuck-like construction.


### Overview

 
   brainfuck          aSSfuck              Ook!
       \                 |                 /
	    \                |                /
		 \               |               /
		  \              |              /
		   \             |             /
		    \  (Compile to bytecode)  / 
			 \           |           /
			  \          |          /
               \         |         /
			    \        |        /
				 \       |       /
				  \      |      /
			       |           |
                   |  Bytecode |  ---------> bfvm (excutes bytecode)
			      /             \
		         /               \
		        /                 \
		       /                   \
		      /   (Decode to any)   \
             /                       \
		    /                         \
	       /                           \	
		voyfuck                      Roadrunner
		
		
		
		
### Bytecode

| Instruction | Description                                                 |
|:-----------:|:------------------------------------------------------------|
|     0000    | Increment the memory cell under the pointer                 |
|     0001    | Decrement the memory cell under the pointer                 |
|     0010    | Move the pointer to the right                               |
|     0011    | Move the pointer to the left                                |
|     0100    | Output the character signified by the cell at the pointer   |
|     0101    | Input a character and store it in the cell at the pointer   |
|     0110    | Jump to the matching `"` if the cell under the pointer is 0 |
|     0111    | Toggles whether subsequent `"` commands start or end a loop |
|     1000    | No Processing                                               |


### Packed bytecode

Bytecode contains 4 bits of binary.
Then make two bytecodes to a byte (8 bits).
50% Packed.

|    packed bytecode   | Description                                                 |
|:--------------------:|:------------------------------------------------------------|
|     0000 0000        | ++*ptr  , ++*ptr                                            |
|     0110 0010        | while(*ptr){ ,  ++ptr                                       |
|     0011 0111        | --pre , }                                                   |


### aSSfuck language

aSSfuck is a joke programming language that uses brainfuck's semantic.


assassassassassassassassassassAsSaSsassassass
assassassassaSsassassassassassassassassassassaSsass
assassaSsassasSasSasSasSAssASSaSsassassASsaSsassASs
assassassassassassassASsASsassassassASsaSsass
assASsasSasSassassassassassassassassassassassassass
assassASsaSsASsassassassASsAssAssAssAssAssAss
ASsAssAssAssAssAssAssAssAssASsaSsassASsaSsASs


It can be compiled to packed bytecodes

20202020202620202020202020202002
20023333710240020420202044204002
40332020202020202040422040111111
1411111141022484

(Converted to HEX by Notepad++)

run on bfvm.

Hello World!

(result)


We can encode packed bytecode to brainfuck!!

++++++++++[>+++++++>++++++++++>+
++>+<<<<-]>++.>+.+++++++..+++.>+
+.<<+++++++++++++++.>.+++.------
.--------.>+.>.
