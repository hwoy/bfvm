#ifndef __BASICPARSE_HPP__

#define __BASICPARSE_HPP__

#include <iostream>
#include <array>
#include <string>
#include <tuple>
#include <type_traits>

#include "bftypedef.hpp"

template <std::size_t N>
using parseinst_t = std::array<std::pair<unsigned int,const std::string> , N >;

template <class ... Strs>
static constexpr auto make_parseinst(Strs ... str) -> parseinst_t<sizeof...(str)>
{
	return parseinst_t<sizeof...(str)> {std::make_pair(0,std::string(str))...};
}

template <class T,std::size_t N>
static INST parseinst(parseinst_t<N> parse,std::basic_istream<T> &in)
{
	char ch;
	
	while(in.get(ch),!in.eof())
	{

		for(unsigned int i=0;i<parse.size();++i)
		{
			if(parse[i].first < parse[i].second.size() && parse[i].second[parse[i].first]==ch)
			{
				if(++parse[i].first >= parse[i].second.size())
					return static_cast<INST>(i);

				continue;
			}
			
			parse[i].first=0;
		}
		
	}

	return INST::NOP;
}


#endif