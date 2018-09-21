#include <iostream>
#include <fstream>

#include "bfengine.hpp"

#include "help.hpp"



int main(int argc , const char *argv[])
{

if(argc<=1)
{
	usage(argv[0],PROGDESC,0,0);
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

if(argc > 2)
{
	fout.open(argv[2],std::ios::binary);
	if(!fout) 
	{
		showerr(err_fout,err,argv[2]);
		return 1;
	}
}



std::ostream &out(argc>2 ? fout: std::cout);
INST inst;
	
while((inst=parseinst(make_parseinst(PROGINST),fin)) != INST::INVALID)
	out << static_cast<char>(inst);
	


	

return 0;
}