#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;
class Triangle: public Shape
{
	public:
		Triangle(string name, double ht, double bs):Shape(0,0,name)
		{	
			height = ht;
			base = bs;
		}
		virtual double area()
		{
			return (height*base)/2;
		}
		virtual void draw()
		{
			for(int row = 1; row <= height; row++)
			{
				for(int col = 0; col < row; col++)
				{
					cout << "*";
				}
				cout << endl;	
			}
			cout<<endl;
		}
		~Triangle(){};
	private:
		double height,base;
};

#endif
