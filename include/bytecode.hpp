union Bytecode
{
	struct
	{
	char byte;
	}packed;

	struct
	{
		unsigned char low:4;
		unsigned char high:4;
	}unpacked;
	
};

