#include <iostream>
#include <fstream>

#include <bfengine.hpp>
#include <help.hpp>


static unsigned int bracket(std::istream &fin,ip_t &ip)
{
	unsigned int n=1;
	INST inst;
	auto looplimit = ip.capacity();
	auto limit = looplimit-ip.size();
			
	while((inst=parseinst(make_parseinst(PROGINST),fin)) != INST::INVALID)
		{
			
			if(inst==INST::BEGIN_WHILE) ++n;
			else if(inst==INST::END_WHILE) --n;
				
			ip.push_back(inst);
			
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


try{
	Tape tape(TAPESIZE);
	BFEngine engine(argc>2 ? fout.rdbuf() : std::cout.rdbuf() );
	ip_t ip(LOOPLIMIT*1024);
	INST inst;
	
	while((inst=parseinst(make_parseinst(PROGINST),fin)) != INST::INVALID)
	{
		ip.clear();
		ip.push_back(inst);
		
		if(inst==INST::BEGIN_WHILE && bracket(fin,ip)) throw Bfexception(Bfexception::eid_while);
		else if(inst==INST::END_WHILE) throw Bfexception(Bfexception::eid_endwhile);

		engine.eval(tape,ip.begin(),ip.end());
	}
	

}catch(const std::exception &e)
{
	std::cerr 	<< std::endl	<< "Exception:" << std::endl
				<< e.what()	<< std::endl;
}
	

return 0;
}