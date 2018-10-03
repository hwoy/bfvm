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


	char _packed;

	struct
	{
		inst_item_t _low:(BIT_OF_UNPACKED_LOW(inst_item_t));
		inst_item_t _high:(BIT_OF_UNPACKED_HIGH(inst_item_t));
	}_unpacked;
	
	inline constexpr Bytecode(char ch):_packed(ch) {}
	inline constexpr Bytecode(INST low,INST high):_unpacked{static_cast<inst_item_t>(low),static_cast<inst_item_t>(high)} {}

	
	Bytecode& packedbytecode(INST low,INST high)
	{
		_unpacked = {static_cast<inst_item_t>(low),static_cast<inst_item_t>(high)};

    	return *this;
	}

	inline constexpr char packed()
	{
		return _packed;
	}

	inline constexpr std::pair<INST,INST> unpacked()
	{
    	return std::pair<INST,INST>{static_cast<INST>(_unpacked._low),static_cast<INST>(_unpacked._high)};
	}

	inline constexpr INST low()
	{
		return static_cast<INST>(unpacked().first);
	}

	inline constexpr INST high()
	{
		return static_cast<INST>(unpacked().second);
	}
};

#endif
