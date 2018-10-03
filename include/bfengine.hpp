#ifndef __BFENGINE_HPP__

#define __BFENGINE_HPP__

#include <iostream>
#include <memory>
#include <string>
#include <tuple>

#include "bftypedef.hpp"
#include "bfexception.hpp"
#include "unittest.hpp"


template <class T>
class Tape: protected std::unique_ptr<T[]>
{
	TEST_CLASSTAPE(T)
				  
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
	
const T * getbaseptr() const
{
	return std::unique_ptr<T[]>::get();
}
	
constexpr const T * getptr() const {return ptr;}
	
constexpr T * getptr_mutable() const {return ptr;}
	
constexpr std::size_t getlength() const {return length;}
	
T * operator ++ () 
{
	if(ptr+1>=std::unique_ptr<T[]>::get()+length) throw Bfexception(Bfexception::eid_incptr);
		
	return ++ptr;
}
	
T * operator -- () 
{
	if(ptr-1<std::unique_ptr<T[]>::get()) throw Bfexception(Bfexception::eid_decptr);
		
	return --ptr;
}
	
T & operator * () const {return *ptr;}
	
T * operator + (std::size_t n) const 
{
	if(ptr+n>=std::unique_ptr<T[]>::get()+length) throw Bfexception(Bfexception::eid_addptr);
		
	return (ptr+n);
}
	
T * operator - (std::size_t n) const 
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
			
		for(V ip=begin;ip != end;)
		{
			int ch;
			switch (*ip)
			{
				case INST::SUCC_VALUE: ++(*tape);	break;
				case INST::PRED_VALUE: --(*tape);	break;
				
				case INST::SUCC_PTR: ++tape; break;
				case INST::PRED_PTR: --tape; break;
			

				case INST::PUT_VALUE: out << reinterpret_cast<const char&>(*tape.getptr()); out.flush(); 	break;
				case INST::GET_VALUE:
				
				ch = std::cin.get();
				
				#if  defined(EOF_UNCHANGED)
					if(ch !=  std::char_traits<char>::eof())
						*tape.getptr_mutable() = ch;
					
				#elif defined(EOF_MINUS1) 
					*tape.getptr_mutable()=(ch == std::char_traits<char>::eof()) ? -1 : ch;
					
				#elif defined(EOF_0) 
					*tape.getptr_mutable()=(ch == std::char_traits<char>::eof()) ? 0 : ch;
					
				#else
					*tape.getptr_mutable() = ch;
				
				#endif
				
				break;
				
				case INST::BEGIN_WHILE: if (!*tape)	std::tie(ip,n) = beginwhile(++ip,end);	break;	
				case INST::END_WHILE: 	if (*tape)	std::tie(ip,n) = endwhile(--ip,begin);	break;
				
				case INST::NOP: break;
				
				default: throw Bfexception(Bfexception::eid_invalidbytecode); 
			}
			
			if(ip!=end) ++ip;
		}
		
		return n;
	}	
	
};


#endif