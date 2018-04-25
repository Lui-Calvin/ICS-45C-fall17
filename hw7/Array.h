#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <iostream>
#include <iomanip>
#include "IndexOutOfBoundsException.h"
using namespace std;

template <typename arrElement>
class Array
{
	private:
		int len;
		arrElement* buf;
	public:
		Array(int length):len(length),buf(new arrElement[length])
		{
		}
		Array(const Array& l):len(l.len),buf(new arrElement[l.len])
		{
			for(int i = 0;i < l.len; i++)
			{
				buf[i] = l.buf[i];
			}
		}
		int length()
		{
			return len;
		}
		arrElement& operator[](int index)
		{
			if(0 <= index && index < len){return buf[index];}
			else
			{
				IndexOutOfBoundsException e;
				throw e;
			}
		}
		
		void print(ostream& out)
		{
			for(int i = 0;i < len; ++i)
			{
				out <<setw(8) << setprecision(2) << fixed << right << buf[i];	
			}
		}
		friend ostream& operator <<(ostream& out,Array& a)
		{
			a.print(out);
			return out;
		}
		friend ostream& operator <<(ostream& out, Array* ap)
		{
			ap->print(out);
			return out;
		}
		~Array()
		{
			delete[] buf;
		}
}; 


#endif
