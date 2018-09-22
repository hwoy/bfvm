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

static void printout(std::istream &in,std::ostream &out,const unsigned int CCOL)
{
	unsigned int col=0;
	char ch;
	while(in.get(ch),!in.eof())
	{
		Bytecode byte{ch};
		INST inst;
	
	if((inst=static_cast<INST>(byte.unpacked.low)) != INST::INVALID)
		{
			out << ersotric[static_cast<std::size_t>(inst)];
			if(!(col=(col+1)%CCOL)) out << std::endl;
		}
	
	if((inst=static_cast<INST>(byte.unpacked.high)) != INST::INVALID)
		{
			out << ersotric[static_cast<std::size_t>(inst)];
			if(!(col=(col+1)%CCOL)) out << std::endl;
		}
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


std::ostream &out(argc>2 ? fout : std::cout);

printout(fin,out,COL);

return 0;
}