# Brainfuck Virtual Machine

The virtual machine for trivial [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) semantic programming language.
This project contains virtual machine, compilers, basic libraries for brainfuck-like programming language construction.

### Overview
Brainfuck virtual machine is a memory-base virtual machine.
Compile (brainfuck,aSSfuck,reversefuck,Alphuck) to bytecode.
Use brainfuck virtual machine to execute bytecodes.
Or Decode bytecodes to (brainfuck,aSSfuck,reversefuck,Alphuck).

```s

 brainfuck\                                         /enecoded to Triplet
  aSSfuck ------------------------> (packed bytecode) ------------------------> (run on bfvm)
   Alphuck/                                         \encoded to Ook!

```
		
		
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

Dumpbin by [hexdmp](https://github.com/hwoy/hexdmp)

```s
$ ass hello.ass
$ hexdmp -h hello.ass.pbc

== hello.ass.pbc ==
0000000000000000: 06 75 00 00 00 00 00 26 00 00 00 20 00 00 00 00 
0000000000000010: 00 02 00 02 33 33 71 02 40 02 04 00 00 00 44 00 
0000000000000020: 40 02 40 33 00 00 00 00 00 00 00 40 42 00 40 11 
0000000000000030: 11 11 14 11 11 11 41 02 24 84 

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
