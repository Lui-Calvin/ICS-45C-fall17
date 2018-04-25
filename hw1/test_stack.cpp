#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{	
	string s = "";
	while(getline(cin,s))
	{
		string str;
		cout << "---------Please Enter String--------" << endl;
		getline(cin,str);
		Stack S;
		cout << "String size: " << str.size() << endl;
		for(int i = 0; i < str.size();i++)
		{
			S.push(str[i]);
		}		
		cout << "---------pusheded to stack--------" << endl;
		cout << "---------popping from stack-------" << endl;
		while(!S.isEmpty())
		{
			cout << S.pop() << endl;
		}
	}
	return 0;
}
