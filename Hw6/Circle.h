#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Circle: public Shape
{
	protected:
		double radius;
	public:
		Circle(string name,double r):Shape(0,0,name)
		{
			radius = r;
		}
		virtual double area()
		{
			return PI * radius * radius;
		}
		virtual void draw()
		{
			for(int row = 0; row <= radius*2; row ++)
			{	
				for(int col = 0; col <= radius*2;col++)
				{
							
					double a = double(row) - radius;
					double b = double(col) - radius;
					double pythTheorem = sqrt((a*a)+(b*b));
					if (pythTheorem < radius + 0.5)
					{
						cout << "* ";
					} else { cout << "  ";} 
				}
				cout << endl;
			}
			cout << endl;
			
		}
		~Circle(){};
	private:
		const double PI = 3.14159;
};
#endif
