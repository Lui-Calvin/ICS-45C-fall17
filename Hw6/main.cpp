#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Picture.h"
using namespace std;
int main()
{

	Picture pic;
	pic.add(new Triangle("FirstTriangle",5.0,5.0));
	pic.add(new Triangle("SecondTriangle",4.0,3.0));
	pic.add(new Circle("FirstCircle",5.0));
	pic.add(new Circle("SecondCircle",10.0));
	pic.add(new Square("FirstSquare",5.0));
	pic.add(new Square("SecondSquare",10.0));
	pic.add(new Rectangle("FirstRectangle",4.0,8.0));
	pic.add(new Rectangle("SecondRectangle",8.0,4.0));
	cout << "Total Area: " <<  pic.totalArea() << endl;
	pic.drawAll();
	return 0;
}
