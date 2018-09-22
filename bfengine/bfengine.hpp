#ifndef __BFENGINE_HPP__

#define __BFENGINE_HPP__

#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include <string>
#include <tuple>


enum class INST : unsigned char
{
		SUCC_VALUE,
		PRED_VALUE,
		SUCC_PTR,
		PRED_PTR,
		PUT_VALUE,
		GET_VALUE,
		BEGIN_WHILE,
		END_WHILE,
		INVALID
};

using inst_t = INST;
using prog_t = std::vector<inst_t>;


class Bfexception final: public std::exception
{
	const std::string msg;
	
	public:
	Bfexception(const std::size_t eid):msg(exc[eid]) {}
	Bfexception(std::string &&msg):msg(std::move(msg)) {}
	
	
	~Bfexception() override = default;
	
	const char* 	what() const noexcept override
{
	return msg.c_str();
}
	
	static const char *exc[];
	enum eid
	{
		eid_incptr,
		eid_decptr,
		eid_addptr,
		eid_subptr,
		eid_while,
		eid_endwhile,
		eid_invalidbytecode
	};
};

const char *Bfexception::exc[]={
	"Can not increase PTR Tape. Please increase mem Tape.",
	"Can not decrease PTR Tape. Please check your code.",
	"Can not Addition PTR Tape. Please increase mem Tape.",
	"Can not Subtraction PTR Tape. Please check your code.",
	"[ must be end with ]. Please check your code.",
	"] must be begin with [. Please check your code.",
	"Invalid virtual machine byte code.",
nullptr};


template <class T>
class Tape: protected std::unique_ptr<T[]>
{
	protected:
	
	T *ptr;
	std::size_t length;
	
	public:
	
Tape(std::size_t s)
{
	settape(s);
}
	
void settape(std::size_t s)
{
	std::unique_ptr<T[]>::reset(new T[s]);
	ptr=std::unique_ptr<T[]>::get();
	length=s;
		
	for(std::size_t i=0;i<length;++i)
		std::unique_ptr<T[]>::get()[i] = 0;	
}
	
void destroytape(void)
{
	std::unique_ptr<T[]>::release();
	ptr=nullptr;
	length=0;
}
	
const T * const getbaseptr() const
{
	return std::unique_ptr<T[]>::get();
}
	
const T * const getptr() const {return ptr;}
	
T * const getptr_mutable() const {return ptr;}
	
std::size_t getlength() const {return length;}
	
T * const operator ++ () 
{
	if(ptr+1>=std::unique_ptr<T[]>::get()+length) throw Bfexception(Bfexception::eid_incptr);
		
	return ++ptr;
}
	
T * const operator -- () 
{
	if(ptr-1<std::unique_ptr<T[]>::get()) throw Bfexception(Bfexception::eid_decptr);
		
	return --ptr;
}
	
T & operator * () const {return *ptr;}
	
T * const operator + (std::size_t n) const 
{
	if(ptr+n>=std::unique_ptr<T[]>::get()+length) throw Bfexception(Bfexception::eid_addptr);
		
	return (ptr+n);
}
	
T * const operator - (std::size_t n) const 
	{
	if(ptr-n<std::unique_ptr<T[]>::get()) throw Bfexception(Bfexception::eid_subptr);
		
	return (ptr-n);
}	

};

class BFEngine
{
	protected:
	
	std::ostream out;

	template <class T>
	static std::pair<T,int> beginwhile(T i, T j,int n=1)
	{
		while(n && i!=j)
		{
			if(*i == INST::BEGIN_WHILE) ++n;
			else if (*i == INST::END_WHILE) --n;
			
			if(n) ++i;
		}
		
		return std::make_pair(i,n);
	}

	template <class T>
	static std::pair<T,int> endwhile(T i, T j,int n=-1)
	{
		while(n && i!=j)
		{
			if(*i == INST::BEGIN_WHILE) ++n;
			else if (*i == INST::END_WHILE) --n;
			
			if(n) --i;
		}
		
		return std::make_pair(i,n);
	}
	
	
	public:
	
	
	explicit BFEngine(std::streambuf *rd):out(rd){}
	

	template <class T,class V>
	int eval(Tape<T> &tape,V begin, V end,int n=0)
	{
		V ip=begin;
		
		
		while(ip != end)
		{
			switch (*ip)
			{
				case INST::SUCC_VALUE: ++(*tape);	break;
				case INST::PRED_VALUE: --(*tape);	break;
				
				case INST::SUCC_PTR: ++tape; break;
				case INST::PRED_PTR: --tape; break;
			

				case INST::PUT_VALUE: out << reinterpret_cast<const char&>(*tape.getptr()); out.flush(); 	break;
				case INST::GET_VALUE: *tape.getptr_mutable() = std::cin.get();	 break;
				
				case INST::BEGIN_WHILE: if (!*tape)	std::tie(ip,n) = beginwhile(++ip,end);	break;	
				case INST::END_WHILE: if (*tape)		std::tie(ip,n) = endwhile(--ip,begin);	break;
				
				case INST::INVALID: break;
				
				default: throw Bfexception(Bfexception::eid_invalidbytecode); 
			}
			
			if(ip!=end) ++ip;
		}
		
		return n;
	}	
	
};


#endif