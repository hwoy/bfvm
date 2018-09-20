#ifndef __BFENGINE_HPP__

#define __BFENGINE_HPP__

#include <iostream>
#include <memory>
#include <exception>
#include <vector>
#include <string>
#include <tuple>

#ifndef CELL_T

#define CELL_T char

#endif

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

using cell_t = CELL_T;

using inst_t = INST;
using prog_t = std::vector<inst_t>;


class Bfexception final: public std::exception
{
	const std::string msg;
	const unsigned int id;
	
	public:
	Bfexception(const std::size_t eid);
	Bfexception(std::string &&msg);
	
	
	~Bfexception() override;
	
	const char* what() const noexcept override;
	
	static const char *exc[];
	enum eid
	{
		eid_incptr,
		eid_decptr,
		eid_addptr,
		eid_subptr,
		eid_while,
		eid_endwhile
	};
};

class Tape: protected std::unique_ptr<cell_t[]>
{
	protected:
	
	cell_t *ptr;
	std::size_t length;
	
	public:
	
	Tape(std::size_t s=512);
	
	void settape(std::size_t s);
	
	void destroytape(void);
	
	const cell_t * const getbaseptr() const;
	
	const cell_t * const getptr() const;
	
	cell_t * const getptr_mutable() const;
	
	std::size_t getlength() const;
	
	cell_t * const operator ++ ();
	
	cell_t * const operator -- ();
	
	cell_t & operator * () const ;
	
	cell_t * const operator + (std::size_t n) const;
	
	cell_t * const operator - (std::size_t n) const ;
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
	
	
	BFEngine(std::streambuf *rd=std::cout.rdbuf());
	

	template <class T>
	int eval(Tape &tape,T begin, T end,int n=0)
	{
		auto ip=begin;
		
		
		while(ip != end)
		{
			switch (*ip)
			{
				case INST::SUCC_VALUE: ++(*tape);	break;
				case INST::PRED_VALUE: --(*tape);	break;
				
				case INST::SUCC_PTR: ++tape; break;
				case INST::PRED_PTR: --tape; break;
			

				case INST::PUT_VALUE: out << static_cast<char>(*tape.getptr()); out.flush(); 	break;
				case INST::GET_VALUE: *tape.getptr_mutable() = std::cin.get();	 break;
				
				case INST::BEGIN_WHILE: if (!*tape)	std::tie(ip,n) = beginwhile(++ip,end);	break;	
				case INST::END_WHILE: if (*tape)		std::tie(ip,n) = endwhile(--ip,begin);	break;
				
				default: break;
			}
			
			if(ip!=end) ++ip;
		}
		
		return n;
	}	
	
};

using parseinst_t = std::vector<  std::pair<unsigned int,const std::string>  >;

template <class ... Strs>
static parseinst_t make_parseinst(Strs ... str)
{
	return parseinst_t {std::make_pair(0,std::string(str))...};
}

INST parseinst(parseinst_t &&parse,std::istream &in);

#endif