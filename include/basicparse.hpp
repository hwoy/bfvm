#ifndef __BASICPARSE_HPP__

#define __BASICPARSE_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

#include "bfengine.hpp"


using parseinst_t = std::vector<  std::pair<unsigned int,const std::string>  >;

template <class ... Strs>
static parseinst_t make_parseinst(Strs ... str)
{
	return parseinst_t {std::make_pair(0,std::string(str))...};
}

template <class T>
static INST parseinst(parseinst_t &&parse,std::basic_istream<T> &in)
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