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
	static_assert(std::is_integral<inst_item_t>::value && sizeof(inst_item_t)==sizeof(char),
                  "Union Bytecode requires inst_item_t = integral type and its size = size of char");

	char packed;

	struct
	{
		inst_item_t low:4;
		inst_item_t high:4;
	}unpacked;
	
};

#endif
