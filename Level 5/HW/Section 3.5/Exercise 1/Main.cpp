//Exercise 3.5.1 asks us to build onto exercise 3.4.2 by declaring Shape's ToString() function as virtual and seeing the effect on the shape pointer to a point

#include "Circle.hpp"		//Include Circle Header File
#include "Array.hpp"		//Include Array Header File

using namespace std;
using JoseAponte::CAD::Point;			//Using the full namespace for Point class
using JoseAponte::CAD::Line;				//Using declaration for using a single class (Line)
using namespace JoseAponte::Containers;	//Using declaration for a complete namespace (Containers)
namespace Circle = JoseAponte::CAD;		//Using the Circle class by creating a shorter alias for the YourName::CAD namespace
using namespace Circle;

int main()
{
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
	//Yes, it printed Point ID: 18467
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?
	//Yes, it printed Line ID: 18467

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?
	//Yes, the code compiled, so it must be possible

	cout << sp->ToString() << endl; // What is printed?
	//It prints 18467, the ID of Point p

	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call the base class assignment in point?
	//No, after removing the call to the base class in the assignment operator of point, a different ID (15724) was printed

	//After declaring the ToString() function of string as virtual, the ToString() function of Point is called when using a Shape* that contains a Point now instead of that from Shape

	return 0;
}