#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
	public:
		Shape(int centerX= 0, int centerY = 0, string name = "Shape")
		{
			x = centerX;
			y = centerY;
			shapeName = name;
		}
		virtual double area() = 0;
		virtual void draw() = 0;
		~Shape(){};
	private:
		int x;
		int y;
		string shapeName;
};
#endif	
