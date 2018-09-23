# Brainfuck Virtual Machine

The virtual machine for trivial brainfuck-cloned semantic programming language.
This project contains virtual machine, compilers, basic libryries for brainfuck-like programming language construction.

### Overview
Compile (brainfuck,aSSfuck,reversefuck,Alphuck) to bytecode.
Use brainfuck virtual machine to execute bytecodes.
Or Decode bytecodes to (brainfuck,aSSfuck,reversefuck,Alphuck).
		
		
### Bytecode

| Instruction | Description                                                                            |
|:-----------:|:---------------------------------------------------------------------------------------|
|     0000    | Increment the memory cell under the pointer                                            |
|     0001    | Decrement the memory cell under the pointer                                            |
|     0010    | Move the pointer to the right                                                          |
|     0011    | Move the pointer to the left                                                           |
|     0100    | Output the character signified by the cell at the pointer                              |
|     0101    | Input a character and store it in the cell at the pointer                              |
|     0110    | Begin of loop structure, Jump out loop structured if the cell under the pointer is 0   |
|     0111    | End of loop structure, Jump to Begin of loop structure                                 |
|     1000    | No Processing                                                                          |


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


```s
AsS
	hello.ass
	Hello World! for aSSfuck
ASS
assassassassassassassassassassAsSaSsassassass
assassassassaSsassassassassassassassassassassaSsass
assassaSsassasSasSasSasSAssASSaSsassassASsaSsassASs
assassassassassassassASsASsassassassASsaSsass
assASsasSasSassassassassassassassassassassassassass
assassASsaSsASsassassassASsAssAssAssAssAssAss
ASsAssAssAssAssAssAssAssAssASsaSsassASsaSsASs

```


#### Compiled to packed bytecodes

```s
$ ass hello.ass

06752020202020262020202020202020
20022002333371024002042020204420
40024033202020202020204042204011
11111411111141022484

(Converted to HEX by Notepad++)

```

#### Run on Brainfuck Virtual Machine
```s
$ bfvm hello.ass.pbc

Hello World!

```

#### Encode packed bytecode to brainfuck!!

```s
$ bc2brainfuck hello.ass.pbc

[+,]++++++++++[>+++++++>++++++++
++>+++>+<<<<-]>++.>+.+++++++..++
+.>++.<<+++++++++++++++.>.+++.--
----.--------.>+.>.
```

- Email: booskillerz@gmail.com
- FB: facebook.com/watt.duean
