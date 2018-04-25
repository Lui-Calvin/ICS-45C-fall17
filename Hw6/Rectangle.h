#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Square.h"
#include <iostream>
using namespace std;

class Rectangle:public Square
{
	public:
		Rectangle(string name, double len, double wid):Square(name,len)
		{
			length = len;
			width = wid;
		}
		virtual double area()
		{
			return length* width;
		}
		virtual void draw()
		{
			for(int row = 0; row < length; row++)
			{
				for(int col = 0; col < width; col++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			cout << endl;
		}
	private:
		double length;
		double width;	
};
#endif
