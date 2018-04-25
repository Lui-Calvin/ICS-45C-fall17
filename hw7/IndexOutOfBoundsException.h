#ifndef INDEXOUTOFBOUNDEXCEPTION_H
#define INDEXOUTOFBOUNDEXCEPTION_H
#include <exception>
using namespace std;

class IndexOutOfBoundsException:public exception
{
	virtual const char* what() const throw()
	{
		return "index was out of bounds:";
	}
};

#endif
