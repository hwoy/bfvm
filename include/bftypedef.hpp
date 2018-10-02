#ifndef __BFTYPEDEF_HPP__
#define __BFTYPEDEF_HPP__

#include <vector>

using inst_item_t = unsigned char;
enum class INST : inst_item_t
{
		SUCC_VALUE,
		PRED_VALUE,
		SUCC_PTR,
		PRED_PTR,
		PUT_VALUE,
		GET_VALUE,
		BEGIN_WHILE,
		END_WHILE,
		NOP
};

using inst_t = INST;
using prog_t = std::vector<inst_t>;

union Bytecode
{

	char packed;

	struct
	{
		inst_item_t low:4;
		inst_item_t high:4;
	}unpacked;
	
};

#endif
