#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * s)
{
	buf = strdup(s);
}

String::String(const String & s)
{
	buf = strdup(s.buf);	
}
String String::operator = (const String & s)
{
	char * oldbuf = buf;
	buf = strdup(s.buf);
	delete[] oldbuf;
	return *this;
}
char & String::operator [](int index)
{
	if(inBounds(index))
	{
		return buf[index];
	}
	cout << "error: index out of bounds" << endl;
	return buf[strlen(buf)];
}
int String::size()
{
	return strlen(buf);
}
String String::reverse()
{
	char temp[strlen(buf) + 1];
	reverse_cpy(temp,buf);
	return String(temp);			
}
void String::print(ostream & out)
{
	int len = strlen(buf);
	for(int i = 0; i < len; ++i)
	{
		cout << buf[i];
	}
	cout << endl;
}
int String::indexOf( const char c)
{
	for(int i =0,len = strlen(buf); i < len; ++i)
	{
		if(buf[i] == c)
		{
			return i;
		}
	}
	return -1;
}
int String::indexOf(const String pattern)
{
	char* loc = strstr(buf,pattern.buf);
	if(loc == '\0')
	{
		return -1;
	}
	return strlen(buf) - strlen(loc);
}
bool String::operator == (const String s)
{
	return strcmp(buf,s.buf) == 0;
}
bool String::operator != (const String s)
{
	return strcmp(buf,s.buf) != 0;
}
bool String::operator > (const String s)
{
	return strcmp(buf,s.buf) > 0;
}
bool String::operator < (const String s)
{
	return strcmp(buf,s.buf) < 0;
}
bool String::operator <= (const String s)
{
	return strcmp(buf,s.buf) <= 0;
}
bool String::operator >= (const String s)
{
	return strcmp(buf,s.buf) >= 0;
}
String String::operator +( const String s)
{
	char arr[strlen(buf) + strlen(s.buf) + 1];
	int i;
	int len1 = strlen(buf),len2 = strlen(s.buf);
	for(i = 0;i < len1;++i)
	{
		arr[i] = buf[i];
	}
	for(int j = 0; j < len2;++j)
	{
		arr[i] = s.buf[j];
		++i;
	}
	arr[i] = '\0';
	return String(arr);
	
}
String String::operator +=(const String s)
{
	int i;
	int len1 = strlen(buf),len2 = strlen(s.buf);	
	char* oldbuf = buf;
	buf = new char[len1 + len2 + 1];
	for(i = 0;i < len1;++i)
	{
		buf[i] = oldbuf[i];
	}
	for(int j = 0; j < len2; ++j)
	{
		buf[i] = s.buf[j];
		++i;
	}
	buf[i] = '\0';
	delete [] oldbuf;
	return *this;
}
void String::read(istream & in)
{
	const int arrsize = 256;
	char arr[arrsize];
	in.getline(arr,arrsize-1);
	char * oldbuf = buf;
	buf = strdup(arr);
	delete[] oldbuf;
}
String::~String()
{
	delete[] buf;
}
void String::final_report_on_allocations()
{
	if(allocations > 0) error("Memory Leak in class String");
	if(allocations > 0) error("too many delete[]s in class String");
	if(allocations == 0)
		cout << "Allocations & deallocations match \n";
}

bool String::inBounds(int i)
{
	return i >= 0 && i < strlen(buf);
}
int String::strlen(const char* src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		++i;
	}
	return i;
		
}
char* String::strcpy(char* dest, const char* src)
{
	int len,i;
	for(i = 0,len = strlen(src); i < len; ++i)
	{	
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;

}	
char* String::strdup(const char *src)
{
	return strcpy(new char[strlen(src)+1],src);
}
int String::strcmp(const char* left, const char* right)
{
	for(int i = 0,len = strlen(left);i < len;++i)
	{
		if(left[i] != right[i])
		{
			return left[i] - right[i];
	
		}
	}
	return 0;
}
int String::strncmp(const char* left,const char* right,int num)
{
	for(int i = 0,len = strlen(left);i < len && i < num;++i)
	{
		if(left[i] != right[i])
		{
			return left[i] - right[i];
		}
	}
	return 0;
}
char * String::strchr(char * str,int c)
{
	return &str[c];
}
const char* String::strstr(const char* haystack,const char* needle)
{
	char* w = (char*)haystack;
	return strstr(w,needle);
}
char* String::strstr(char* haystack, const char* needle)
{
	int needle_len = strlen(needle),i = 0,len = strlen(haystack);
	cout << i << endl;
	while(i < len)
	{
		if (strncmp(strchr(haystack,i),needle,needle_len) == 0)
		{
			return & haystack[i];
		}
		++i;
	}
	return '\0';
}
void String::reverse_cpy(char* dest, const char* src)
{
	int j = 0;
	for (int i = strlen(src) - 1; i >= 0;--i)
	{
		dest[j] = src[i];
		++j;
	}
	dest[j] = '\0';
}
int String::allocations = 0;
char* String::new_char_array(int n_bytes)
{
	++allocations;
	cout << "return new char array" << endl;
	return new char[n_bytes];
}
void String::delete_char_array(char* p)
{
        --allocations;
        if(allocations < 0) error("more delete[] than new[]");
        delete[] p;
}
void String::error(const char* p)
{
        cerr << "Error(class String): " << p << endl;
}


ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}

istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
