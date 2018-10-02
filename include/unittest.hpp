#ifndef __UNITTEST_HPP__
#define __UNITTEST_HPP__

#include <type_traits>

// ========================  test PROGINST ======================== //


namespace proginst_trait
{
	template <class ...Args>
	static constexpr std::size_t number_of_element(Args ...args) {return sizeof...(args);}

	template <class ...Args>
	using type = typename std::common_type<Args ...>::type;
	
}

#define TEST_PROGINST(__PROGINST__) static_assert(proginst_trait::number_of_element(__PROGINST__)==8,"Number of Element of PROGINST must be 8");



// ========================  test class Tape ======================== //

#define TEST_CLASSTAPE(__CELL_T__) static_assert(std::is_integral<__CELL_T__>::value,"class Tape requires integral type");


// ========================  test union Bytecode ======================== //

#define TEST_UNIONBYTECODE(__INST_ITEM_T__,__CHAR_T__) static_assert(std::is_integral<__INST_ITEM_T__>::value && sizeof(__INST_ITEM_T__)==sizeof(__CHAR_T__),"Union Bytecode requires inst_item_t = integral type and its size = size of char");


// ========================  test common type ======================== //

#define TEST_COMMON_TYPE(__TYPEARGS__,__TEST__) static_assert(std::is_same<proginst_trait::type<__TYPEARGS__ ...> , __TEST__>::value,"Common type and test are not same");

#endif
