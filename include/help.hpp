#include "common.hpp"

static void usage(const char *path,const char *str)
{
	auto gpath=path::grap(path);
	
	std::cerr << std::endl << gpath << " is " << str << std::endl << std::endl
						   << gpath << " input-file" << std::endl
						   << gpath << " input-file output-file"  << std::endl << std::endl;

}


