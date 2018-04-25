#include "String.h"
#include <iostream>
using namespace std;

String::String(const char * s)
{
	head = String::ListNode::stringToList(s);
}
String::String(const String & s)
{
	head = String::ListNode::copy(s.head);
}

String String::operator = ( const String & s)
{
	String::ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}
char& String::operator [] (const int index)
{
	if (!inBounds(index))
	{
		cout << "error index out of bounds" << endl;
		static char nullT = '\0';
		return nullT;
	}
	int i = 0;
	for(String::ListNode * p = head;p;p=p->next,++i)
	{
		if(i == index)
		{
			return(p->info);
		}
	}
}
int String::size() const
{
	return String::ListNode::length(head);
}
int String::indexOf(char c) const
{
	int index = 0;
	for(ListNode * p = head; p != nullptr; p = p->next,index++)
	{
		if(p->info == c)
		{
			return index;
		}	
	}
	return -1;
}
bool String::operator == (const String & s) const
{
	if(String::ListNode::compare(head,s.head) == 0)
	{
		return true;
	}
	return false;
}
bool String::operator < (const String & s) const
{
	return String::ListNode::compare(head,s.head) < 0;
}
String String::operator + (const String & s) const
{
	String ret = String();
	ret.head = String::ListNode::append(head,s.head);
	return ret;
}
String String::operator += (const String & s)
{
	String::ListNode * temp = head;
	head = String::ListNode::append(temp,s.head);
	String::ListNode::deleteList(temp);
	return *this;
}
String String::reverse() const
{
	String ret = String();
	ret.head = String::ListNode::reverse(head);
	return ret;
}
void String::print(ostream & out)const
{
	for(String::ListNode * p = head; p != nullptr; p = p->next)
	{
		out << p->info;
	}
	out << endl;

}
void String::read(istream& in)
{
	int arrSize = 256;
	char input[arrSize];
	in.getline(input,arrSize-1);
	String::ListNode * temp = head;
	head = String::ListNode::stringToList(input);
	String::ListNode::deleteList(temp);
}
String::~String()
{
	String::ListNode::deleteList(head);
}
String::ListNode * String::ListNode::stringToList(const char * s)
{
	if (*s=='\0')
	{
		return nullptr;
	}
	return new ListNode(*s++,String::ListNode::stringToList(s));
	
}
String::ListNode * String::ListNode::copy(String::ListNode * L)
{
	if(L == nullptr)
	{
		return nullptr;
	}
	return new ListNode(L->info,copy(L->next));
}
String::ListNode * String::ListNode::reverse(String::ListNode * L)
{
	String::ListNode * R = nullptr;
	for(String::ListNode * p = L;p!= nullptr; p = p->next)
	{
		R = new String::ListNode(p->info,R);
	}
	return R;
}
String::ListNode* String::ListNode::append(String::ListNode *L1, String::ListNode * L2)
{
	if(L1 == nullptr)
	{
		return L1 = String::ListNode::copy(L2);
	}
	return new String::ListNode(L1->info,String::ListNode::append(L1->next,L2));
}
int String::ListNode::compare(String::ListNode * L1, String::ListNode * L2)
{
	if (L1 == nullptr && L2 == nullptr){return 0;}
	else if(L1 == nullptr) { return 0 - (L2->info); }
	else if (L2 == nullptr) {return L1->info - 0;}
	else if (L1->info!=L2->info){return ((L1->info) - (L2->info));}
	else return String::ListNode::compare(L1->next,L2->next);
}
void String::ListNode::deleteList(String::ListNode * L)
{
	while(L)
	{
		ListNode * p = L;
		L = L->next;
		delete p;
	}
	
}
int String::ListNode::length(ListNode * L)
{
	if (L == nullptr)
	{
		return 0;
	}
	return 1 + String::ListNode::length(L->next);
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
