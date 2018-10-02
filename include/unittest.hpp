// ========================  test PROGINST ======================== //


struct proginst_trait
{
	template <class ...Args>
	static constexpr std::size_t number_of_element(Args ...args) {return sizeof...(args);}
	
};

#define TEST_PROGINST(__PROGINST__) static_assert(proginst_trait::number_of_element(__PROGINST__)==8,"Number of Element of PROGINST must be 8");


// ========================  test PROGINST ======================== //
