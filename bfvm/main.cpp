#include <iostream>
#include <fstream>

#include <bfengine.hpp>
#include <help.hpp>
#include "config.hpp"

static unsigned int bracket(std::istream &fin,prog_t &prog)
{
	unsigned int n=1;
	INST inst;
	auto looplimit = prog.capacity();
	auto limit = looplimit-prog.size();
	
	char ch;	
	while(fin.get(ch),inst=static_cast<INST>(ch),!fin.eof())
		{
			
			if(inst==INST::BEGIN_WHILE) ++n;
			else if(inst==INST::END_WHILE) --n;
				
			prog.push_back(inst);
			
			if(!n) break;
			if(!(--limit)) throw Bfexception("Large [] loop Over the limit:" + std::to_string(looplimit) + " ,Please check your code.");
		}
		
	return n;
}

int main(int argc , const char *argv[])
{

if(argc<=1)
{
	usage(argv[0],PROGDESC,TAPESIZE,sizeof(cell_t));
	return 0;
}

std::ifstream fin;
std::ofstream fout;

if(argc > 1)
{
	fin.open(argv[1],std::ios::binary);
	if(!fin) 
	{
		showerr(err_fin,err,argv[1]);
		return 1;
	}
}

if(argc > 2)
{
	fout.open(argv[2],std::ios::binary);
	if(!fout) 
	{
		showerr(err_fout,err,argv[2]);
		return 1;
	}
}


try{
	Tape<cell_t> tape(TAPESIZE);
	BFEngine engine(argc>2 ? fout.rdbuf() : std::cout.rdbuf() );
	prog_t prog(LOOPLIMIT*1024);
	char ch;
	while(fin.get(ch),!fin.eof())
	{
		prog.clear();
		INST inst=static_cast<INST>(ch);
		prog.push_back(inst);
		
		if(inst==INST::BEGIN_WHILE && bracket(fin,prog)) throw Bfexception(Bfexception::eid_while);
		else if(inst==INST::END_WHILE) throw Bfexception(Bfexception::eid_endwhile);

		engine.eval(tape,prog.begin(),prog.end());
	}
	

}catch(const std::exception &e)
{
	std::cerr 	<< std::endl	<< "Exception:" << std::endl
				<< e.what()	<< std::endl;
}
	

return 0;
}