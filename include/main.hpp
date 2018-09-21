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

if(argc >= 2)
{
	fout.open(argc==2 ? std::string(argv[1])+".bfc": std::string(argv[2]),std::ios::binary);
	if(!fout) 
	{
		showerr(err_fout,err,(argc==2 ? std::string(argv[1])+".bfc": std::string(argv[2])).c_str());
		return 1;
	}
}



std::ostream &out(fout);
INST inst;
	
while((inst=parseinst(make_parseinst(PROGINST),fin)) != INST::INVALID)
	out << static_cast<char>(inst);
	


	

return 0;
}