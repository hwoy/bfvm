#include "common.hpp"

static void usage(const char *path,const char *str,std::size_t tapesize,std::size_t cellsize)
{
	auto gpath=path::grap(path);
	
	std::cerr << std::endl << gpath << " is " << str << std::endl << std::endl
						  << gpath << " input-file" << std::endl
						  << gpath << " input-file output-file" << std::endl << std::endl;
	
	std::cerr << "TAPESIZE = " << tapesize << ", CELLSIZE = " << cellsize*8 << " bits"<< std::endl << std::endl;
}


