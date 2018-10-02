#include <iostream>
#include <fstream>
#include <sstream>

#include "bfengine.hpp"
#include "basicparse.hpp"
#include "help.hpp"

#define EXTEND ".pbc"


int main(int argc , const char *argv[])
{

if(argc<=1)
{
	usage(argv[0],PROGDESC);
	return 0;
}

std::ifstream fin;


if(argc > 1)
{
	fin.open(argv[1]);
	if(!fin) 
	{
		showerr(err_fin,err,argv[1]);
		return 1;
	}
}

std::ofstream fout;

if(argc >= 2)
{
	fout.open(argc==2 ? std::string(argv[1])+EXTEND : std::string(argv[2]),std::ios::binary);
	if(!fout) 
	{
		showerr(err_fout,err,(argc==2 ? std::string(argv[1])+EXTEND : std::string(argv[2])).c_str());
		return 1;
	}
}

INST lowinst,highinst;
	
do
{
	if((lowinst=parseinst(make_parseinst(PROGINST),fin)) , !fin.eof())
	{
	
		highinst=parseinst(make_parseinst(PROGINST),fin);
	
		Bytecode byte;
		byte.unpacked.low=static_cast<inst_item_t>(lowinst);
		byte.unpacked.high=static_cast<inst_item_t>(highinst);
	
		fout.put(byte.packed);
	}
	
}while(!fin.eof());
	

return 0;
}


