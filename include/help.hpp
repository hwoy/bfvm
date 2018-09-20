struct path{
	static constexpr const char * const grap(const char * const path)
	{
		return grap(path,path);
	}
	
	private:
	static constexpr const char * const grap(const char * const gpath,const char * const path)
	{
		return *path?  grap( (*path=='\\' || *path =='/') ? path+1 : gpath,path+1) : gpath;
	}
};

static void showerr (unsigned int id,const char *err[],const char *str)
{
	std::cerr << "\nERROR ID " << id  << " : " << err[id] << (str?str:"") << std::endl;
}


static void usage(const char *path,const char *str,std::size_t tapesize,std::size_t cellsize)
{
	auto gpath=path::grap(path);
	
	std::cerr << std::endl << gpath << " is " << str << std::endl << std::endl
						  << gpath << " input-file" << std::endl
						  << gpath << " input-file output-file" << std::endl << std::endl;
	
	std::cerr << "TAPESIZE = " << tapesize << ", CELLSIZE = " << cellsize*8 << " bits"<< std::endl << std::endl;
}

static const char *err[] = {"Can not access INPUT FILE: ","Can not access OUTPUT FILE: ",nullptr};

enum{
	err_fin,err_fout
};


#ifndef LOOPLIMIT
#define LOOPLIMIT 64
#endif

#ifndef TAPESIZE
#define TAPESIZE 512
#endif

