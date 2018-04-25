#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;

class Square:public Shape
{	
	public:
	Square(string name, double sideLength):Shape(0,0,name)
	{
		side = sideLength;
	}
	virtual double area()
	{
		return side*side;
	}
	virtual void draw()
	{
		for(int row = 0; row < side; row++)
		{
			for(int col = 0;col < side;col++)
			{
				cout << "* ";	
			}
			cout << endl;
		}
		cout << endl;
	}
	~Square(){};
	private:
		int side;



};
#endif
