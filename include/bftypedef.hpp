#ifndef __BFTYPEDEF_HPP__
#define __BFTYPEDEF_HPP__

#include <vector>
#include <tuple>

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

#ifndef CELL_T
#define CELL_T char
#endif

using cell_t = CELL_T;

using inst_t = INST;
using prog_t = std::vector<inst_t>;

#define BIT_OF_UNPACKED(X) (sizeof(X)*8)
#define BIT_OF_UNPACKED_LOW(X) (BIT_OF_UNPACKED(X)/2)
#define BIT_OF_UNPACKED_HIGH(X) (BIT_OF_UNPACKED(X)-BIT_OF_UNPACKED_LOW(X))

union Bytecode
{
	TEST_UNIONBYTECODE(inst_item_t,char)


	char __packed__;

	struct
	{
		inst_item_t __low__:(BIT_OF_UNPACKED_LOW(inst_item_t));
		inst_item_t __high__:(BIT_OF_UNPACKED_HIGH(inst_item_t));
	}__unpacked__;
	
	Bytecode()=delete;
	inline constexpr Bytecode(char ch):__packed__(ch) {}
	inline constexpr Bytecode(INST low,INST high):__unpacked__{static_cast<inst_item_t>(low),static_cast<inst_item_t>(high)} {}


	inline constexpr char packed() const
	{
		return __packed__;
	}

	inline constexpr std::pair<INST,INST> unpacked() const
	{
    	return std::pair<INST,INST>{static_cast<INST>(__unpacked__.__low__),static_cast<INST>(__unpacked__.__high__)};
	}

	inline constexpr INST low() const
	{
		return unpacked().first;
	}

	inline constexpr INST high() const
	{
		return unpacked().second;
	}
};

#endif
