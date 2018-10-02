#include <iostream>
#include <fstream>
#include <string>

#include "bftypedef.hpp"
#include "bfexception.hpp"
#include "help.hpp"

#ifndef COL
#define COL 32
#endif

// ========================  test PROGINST ======================== //

class proginst_trait
{
	public:
	template <class T,std::size_t N>
	static constexpr std::size_t number_of_element(const T (&)[N]) {return N;}
	
};

static const char *ersotric[]={PROGINST};

static_assert(proginst_trait::number_of_element(ersotric)==8,"Number of Element of PROGINST must be 8");


// ========================  test PROGINST ======================== //


static unsigned int printersoteric(std::ostream &out,INST inst,const char *ersotric[],unsigned int col,const unsigned int CCOL,const char *whitespace)
{
	if(inst < INST::NOP)
		{
			out << ersotric[static_cast<std::size_t>(inst)] << whitespace;
			if(!(col=(col+1)%CCOL)) out << std::endl;
		}
	else if(inst > INST::NOP) throw Bfexception(Bfexception::eid_invalidbytecode);
	return col;
}

static void printout(std::istream &in,std::ostream &out,const char *ersotric[],const unsigned int CCOL,const char *whitespace)
{
	unsigned int col=0;
	char ch;
	while(in.get(ch),!in.eof())
	{
		Bytecode byte{ch};
	
		col=printersoteric(out,static_cast<INST>(byte.unpacked.low),ersotric,col,CCOL,whitespace);
		
		col=printersoteric(out,static_cast<INST>(byte.unpacked.high),ersotric,col,CCOL,whitespace);
	
	}
}

int main(int argc , const char *argv[])
{

if(argc<=1)
{
	usage(argv[0],PROGDESC2);
	return 0;
}

std::ifstream fin;


if(argc > 1)
{
	fin.open(argv[1],std::ios::binary);
	if(!fin) 
	{
		showerr(err_fin,err,argv[1]);
		return 1;
	}
}

std::ofstream fout;

if(argc > 2)
{
	fout.open(argv[2]);
	if(!fout) 
	{
		showerr(err_fout,err,argv[2]);
		return 1;
	}
}

try{
	printout(fin,(argc>2 ? fout : std::cout),ersotric,COL,WHITESPACE);
	
}catch(const std::exception &e)
{
	std::cerr 	<< std::endl	<< "Exception:" << std::endl
				<< e.what()	<< std::endl;
}

return 0;
}