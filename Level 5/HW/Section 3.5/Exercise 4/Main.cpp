//Exercise 3.5.4 asks us to build onto exercise 3.5.3 by making a pure virtual Draw() function in the Shape class and making Shape a true abstraction
//Following that, we added overreriding Draw() functions to point, line, and circle

#include "Circle.hpp"		//Include Circle Header File
#include "Array.hpp"		//Include Array Header File

using namespace std;
using JoseAponte::CAD::Point;			//Using the full namespace for Point class
using JoseAponte::CAD::Line;				//Using declaration for using a single class (Line)
using namespace JoseAponte::Containers;	//Using declaration for a complete namespace (Containers)
namespace Circ = JoseAponte::CAD;		//Using the Circle class by creating a shorter alias for the YourName::CAD namespace
using namespace Circ;

int main()
{

	Shape* shapes[10];					//Initializng a shape pointer array w/ 10 elements
	shapes[0] = new Line;				//First element is a line
	shapes[1] = new Point;				//Second element is a point
	shapes[2] = new Point;				//Third element is a point
	shapes[3] = new Line;				//Fourth element is a line
	shapes[4] = new Line;				//Fifth element is a line
	shapes[5] = new Point;				//Sixth element is a point
	shapes[6] = new Point;				//Seventh element is a point
	shapes[7] = new Line;				//Eighth element is a line
	shapes[8] = new Circle;				//Ninth element is a circle
	shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));	//Tenth element is a line
	for (int i = 0; i != 10; i++) shapes[i]->Draw();		//Sending the elements to the draw function
	for (int i = 0; i != 10; i++) delete shapes[i];			//Delete all of the elements

	//After making the draw function a pure virtual function, the code would not compile because there was no overrider
	//However, after adding overrider functions in point, line, and circle, the code compiles and the "drawings" are printed
	return 0;
}