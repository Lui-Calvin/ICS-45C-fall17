#include "String.h"

int main()
{
	cout << "Creating String \"first\"" << endl;
	String first("first");
	cout << "Creating String \"second\"" << endl;
	String second("second");
	cout << "Creating String \"third\"" << endl;
	String third("third");
	first += second;

	cout << "+=: first += second" << first << endl;
	cout << "+ : First + third ->";   
	cout << first + third << endl;
	cout << "firstsecond < firstsecond: ";
	cout << (first < first) << endl;
	cout << "firstsecond < second: ";
	cout << (first < second) << endl;
	cout << "second == third" << endl;
	cout << (second == third) << endl;
	cout << "second == second" << endl;
	cout << (second == second) << endl;
	cout << "size of \"firstsecond\": ";
	cout << first.size() << endl;
	cout << "reverse of \"firstsecond\": ";
	cout << first.reverse() << endl;
	cout << "index of \'e\'	in \"second\": ";
	cout << second.indexOf('e') << endl;
	String input = String();
	cout << "enter test String: ";
	cin >> input;
	cout << "entered: " << input << endl;
	
	return 0;

}
