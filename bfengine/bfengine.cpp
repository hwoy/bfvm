#include "bfengine.hpp"

Bfexception::Bfexception(const std::size_t eid):msg(exc[eid]),id(eid) {}
Bfexception::Bfexception(std::string &&msg):msg(std::move(msg)),id(-1U) {}
	
	
Bfexception::~Bfexception(){}
	
const char* Bfexception::what() const noexcept
{
	return msg.c_str();
}
	
const char *Bfexception::exc[]={
	"Can not increase PTR Tape. Please increase mem Tape.",
	"Can not decrease PTR Tape. Please check your code.",
	"Can not Addition PTR Tape. Please increase mem Tape.",
	"Can not Subtraction PTR Tape. Please check your code.",
	"[ must be end with ]. Please check your code.",
	"] must be begin with [. Please check your code.",
nullptr};


	
Tape::Tape(std::size_t s)
{
	settape(s);
}
	
void Tape::settape(std::size_t s)
{
	reset(new cell_t[s]);
	ptr=get();
	length=s;
		
	for(std::size_t i=0;i<length;++i)
		get()[i] = 0;	
}
	
void Tape::destroytape(void)
{
	release();
	ptr=nullptr;
	length=0;
}
	
const cell_t * const Tape::getbaseptr() const
{
	return get();
}
	
const cell_t * const Tape::getptr() const {return ptr;}
	
cell_t * const Tape::getptr_mutable() const {return ptr;}
	
std::size_t Tape::getlength() const {return length;}
	
cell_t * const Tape::operator ++ () 
{
	if(ptr+1>=get()+length) throw Bfexception(Bfexception::eid_incptr);
		
	return ++ptr;
}
	
cell_t * const Tape::operator -- () 
{
	if(ptr-1<get()) throw Bfexception(Bfexception::eid_decptr);
		
	return --ptr;
}
	
cell_t & Tape::operator * () const {return *ptr;}
	
cell_t * const Tape::operator + (std::size_t n) const 
{
	if(ptr+n>=get()+length) throw Bfexception(Bfexception::eid_addptr);
		
	return (ptr+n);
}
	
cell_t * const Tape::operator - (std::size_t n) const 
	{
	if(ptr-n<get()) throw Bfexception(Bfexception::eid_subptr);
		
	return (ptr-n);
}	


BFEngine::BFEngine(std::streambuf *rd):out(rd){}

INST parseinst(parseinst_t &&parse,std::istream &in)
{
	char ch;
	
	while(in.get(ch),!in.eof())
	{

		for(unsigned int i=0;i<parse.size();++i)
		{
			if(parse[i].first < parse[i].second.size() && parse[i].second[parse[i].first]==ch)
			{
				if(++parse[i].first >= parse[i].second.size())
					return static_cast<INST>(i);

				continue;
			}
			
			parse[i].first=0;
		}
		
	}

	return INST::INVALID;
}

