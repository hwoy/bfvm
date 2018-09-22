#ifndef __BYTECODE_HPP__
#define __BYTECODE_HPP__

union Bytecode
{

	char packed;

	struct
	{
		unsigned char low:4;
		unsigned char high:4;
	}unpacked;
	
};

#endif
