#include <iostream>
#include <fstream>
#include <array>
#include <string>

#include "bfengine.hpp"
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

template <class ... Args>
static const std::string vmtoesotric(INST inst,Args... str)
{
	const std::array<std::string,sizeof...(str)> arr{str...};
	return arr[static_cast<std::size_t>(inst)];
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

unsigned int col=0;
char ch;
while(fin.get(ch),!fin.eof())
{
	out << vmtoesotric(reinterpret_cast<INST&>(ch),PROGINST);
	if(!(col=(col+1)%COL)) out << std::endl;
}
	

return 0;
}