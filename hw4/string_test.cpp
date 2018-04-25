#include "String.h"

int main()
{
	{
	cout << "-----construction and printing-----" << endl;
	cout << "Constructing String \"hello\"" << endl;
	String first("Hello");
	cout << "Constructing String \"World\"" << endl;
	String second("World");
	cout << "Constructing String \"Calvin\"" << endl;
	String third("Calvin");
	cout << "Constructing String \"Lui\"" << endl;
	String fourth("Lui");
	cout << "Printing:" << endl;
	cout << first << endl;
	cout << second << endl;
	cout << third << endl;
	cout << fourth << endl;
	cout << "-----Testing assignments-----" << endl;
	cout << "=:" << endl;
	cout << "Setting \"Hello\" to \"Hi\"" << endl;
	cout << "Setting \"World\" to \"All\"" << endl;
	first = String("Hi");
	second = String("All");
	cout << first << endl;
	cout << second << endl;
	cout << "[]:" << endl;
	cout << first[0] << endl;
	cout << first[1] << endl;
	cout << "-----testing size-----" << endl;
	cout << "size of \"Hi\":" << first.size() << endl;
	cout << "size of \"All\":" << second.size() << endl;
	cout << "-----testing indexOf(char)-----" << endl;
	cout << "index of l in \"Calvin\":" << third.indexOf('l') << endl;
	cout << "index of u in \"Lui\":" << fourth.indexOf('u') << endl;
	cout << "-----testing indexOf(pattern)-----" << endl;
	cout << "index of ll in \"All\":" << second.indexOf(String("ll")) << endl;
	cout << "index of vin in \"Calvin\":" << third.indexOf(String("vin")) << endl;
	cout << "----testing == -----" << endl;
	cout << "\"Calvin\" == \"Lui\" :" << (third == fourth) << endl;
	cout << "\"Calvin\" == \"Calvin\" :" << (third == third) << endl;
	cout << "-----testing != -----" << endl;
	cout << "\"Calvin != \"Lui\": " << (third != fourth) << endl;
	cout << "\"Calvin != \"Calvin\": " << (third != third) << endl;
	cout << "-----testing > -----" << endl;
	cout << "\"Hi\" > \"Hi\": " << (first > first) << endl;
	cout << "\"Hi\" > \"All\": " << (first > second) << endl;
	cout << "----- testing < -----" << endl;
	cout << "\"Hi\" < \"Hi\": " << (first < first) << endl;
	cout << "\"Hi\" < \"All\": " << (first < second) << endl;
	cout << "----- testing <= ------" << endl;
	cout << "\"Hi\" <= \"Hi\": " << (first <= first) << endl;
	cout << "\"Hi\" <= \"All\": " << (first <= second) << endl;
	cout << "-----testing >= -----" << endl;
	cout << "\"Hi\" >= \"Hi\": " << (first >= first) << endl;
	cout << "\"Hi\" >= \"All\": " << (first >= second) << endl;
	cout << "-----testing reverse-----" << endl;
	cout << third.reverse() << endl;
	cout << fourth.reverse() << endl;
	cout << "-----testing concatenation -----" << endl;
	cout << (first + second) << endl;
	cout << (third += fourth) << endl;
	}
	String::final_report_on_allocations();
	return 0;

}
