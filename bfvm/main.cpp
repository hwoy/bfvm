#include <iostream>
#include <fstream>
#include <list>

#include <bfengine.hpp>
#include <help.hpp>
#include "config.hpp"

static void usage(const char *path,const char *str,std::size_t tapesize,std::size_t cellsize)
{
	usage(path,str);
	
	std::cerr << "TAPESIZE = " << tapesize << ", CELLSIZE = " << cellsize*8 << " bits"<< std::endl << std::endl;
	
	std::cerr << "*** "
	
	#if  defined(EOF_UNCHANGED)
			"If takes an EOF, unchanges a current value of cell."
					
	#elif defined(EOF_MINUS1) 
			"If takes an EOF, changes a current value of cell to -1"
					
	#elif defined(EOF_0) 
			"If takes an EOF, changes a current value of cell to 0"
					
	#else
			"If takes an EOF, changes a current value of cell to this EOF value"

				
	#endif
	
	<< " ***" << std::endl << std::endl
	
	<< "***** Suggest EOF = " << std::char_traits<char>::eof() << " *****" << std::endl << std::endl;
}




static bool unpackedstream(std::list<INST> &unpackedlst,std::istream &packedis)
{
	char ch;
	if(packedis.get(ch),packedis.eof())
		return false;
	
	Bytecode byte{ch};
	unpackedlst.push_back(static_cast<INST>(byte.unpacked.low));
	unpackedlst.push_back(static_cast<INST>(byte.unpacked.high));
	
	return true;

}

static unsigned int bracket(std::list<INST> &unpackedlst,std::istream &fin,prog_t &prog)
{
	unsigned int n=1;
	auto looplimit = prog.capacity();
	auto limit = looplimit-prog.size();
		
	while(!unpackedlst.empty() || (unpackedstream(unpackedlst,fin)))
	{
		
		INST inst=static_cast<INST>(unpackedlst.front());
		unpackedlst.pop_front();
		
		if(inst==INST::BEGIN_WHILE) ++n;
		else if(inst==INST::END_WHILE) --n;
				
		prog.push_back(inst);
			
		if(!n) break;
		if(!(--limit)) throw Bfexception("Loop Over the limit:" + std::to_string(looplimit) + " ,Please check your code.");
		
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
	std::list<INST> unpackedlst;
	
	while(!unpackedlst.empty() || (unpackedstream(unpackedlst,fin)))
	{

		INST inst=static_cast<INST>(unpackedlst.front());
		unpackedlst.pop_front();
		
		prog.clear();
		prog.push_back(inst);
		
		if(inst==INST::BEGIN_WHILE && bracket(unpackedlst,fin,prog)) throw Bfexception(Bfexception::eid_while);
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
