#include <iostream>
#include <fstream>
#include <string>

#include "bfengine.hpp"
#include "bytecode.hpp"
#include "common.hpp"

#ifndef COL
#define COL 32
#endif


static void usage(const char *path,const char *str)
{
	auto gpath=path::grap(path);
	
	std::cerr << std::endl << gpath << " is " << str << std::endl << std::endl
						  << gpath << " input-file" << std::endl
						  << gpath << " input-file output-file" << std::endl << std::endl;
	
}

static const char *ersotric[]={PROGINST};

static unsigned int printersoteric(std::ostream &out,INST inst,const char *ersotric[],unsigned int col,const unsigned int CCOL)
{
	if(inst != INST::INVALID)
		{
			out << ersotric[static_cast<std::size_t>(inst)];
			if(!(col=(col+1)%CCOL)) out << std::endl;
		}
	return col;
}

static void printout(std::istream &in,std::ostream &out,const char *ersotric[],const unsigned int CCOL)
{
	unsigned int col=0;
	char ch;
	while(in.get(ch),!in.eof())
	{
		Bytecode byte{ch};
	
		col=printersoteric(out,static_cast<INST>(byte.unpacked.low),ersotric,col,CCOL);
		
		col=printersoteric(out,static_cast<INST>(byte.unpacked.high),ersotric,col,CCOL);
	
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

printout(fin,(argc>2 ? fout : std::cout),ersotric,COL);

return 0;
}