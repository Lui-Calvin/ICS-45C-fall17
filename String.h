#ifndef _String_H
#define _String_H

class String
{
	public:
		explicit String(const char * s= "");
		/*
		String(const String & s);
		String operator = (const String & s);
		char & operator [] (int index);
		int size();
		String reverse();
		int indexOf(const char c);
		int indexOf(const String pattern);
		bool operator == (const String s);
		bool operator != (const String s);
		bool operator > (const String s);
		bool operator < (const String s);
		bool operator <= (const String s);
		bool operator >= (const String s);
		String operator + (const String s);
		String operator += (const Strings);
		void print(ostream & out);
		void read(istream & in);
		*/
		~String();
	private:
		bool inBounds(int i);
		static char * strcpy(char * dest, const char * src);
		static char * strdup(const char * src);
		static int strcmp(const char * left, const char * right);
		static int strncmp(const char * left, const char * right,int num);
		static char * strchr(char * src,int c);
		static const char * strstr(const char* haystack,const char* needle);
		static char * strstr(char * haystack, const char * needle);
		char * buf;	
		
};
#endif
