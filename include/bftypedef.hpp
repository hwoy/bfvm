#ifndef __BFTYPEDEF_HPP__
#define __BFTYPEDEF_HPP__

#include <vector>

#include "unittest.hpp"

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

#define BIT_OF_UNPACKED(X) (sizeof(X)*8/2)

union Bytecode
{
	TEST_UNIONBYTECODE(inst_item_t,char)

	char packed;

	struct
	{
		inst_item_t low:(BIT_OF_UNPACKED(inst_item_t));
		inst_item_t high:(BIT_OF_UNPACKED(inst_item_t));
	}unpacked;
	
};

#endif
