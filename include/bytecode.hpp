union Bytecode
{
	struct
	{
	char byte;
	}packed;

	struct
	{
		char low:4;
		char high:4;
	}unpacked;
	
};

