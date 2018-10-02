#ifndef __BFEXCEPTION_HPP__
#define __BFEXCEPTION_HPP__

#include <exception>
#include <string>


class Bfexception final: public std::exception
{
	const std::string msg;
	
	public:
	Bfexception(const std::size_t eid):msg(exc[eid]) {}
	Bfexception(std::string &&msg):msg(std::move(msg)) {}
	
	
	~Bfexception() override = default;
	
	const char* what() const noexcept override
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
	"Can not increase cell PTR. Please increase Tape Size.",
	"Can not decrease cell PTR. Please check your code.",
	"Can not Addition cell PTR. Please increase Tape Size.",
	"Can not Subtraction cell PTR. Please check your code.",
	"BEGIN_WHILE must be end with END_WHILE. Please check your code.",
	"END_WHILE must be begin with BEGIN_WHILE. Please check your code.",
	"Invalid virtual machine byte code.",
nullptr};


#endif