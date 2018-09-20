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



static const char *err[] = {"Can not access INPUT FILE: ","Can not access OUTPUT FILE: ",nullptr};

enum{
	err_fin,err_fout
};

