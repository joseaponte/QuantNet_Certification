//Exercise 3.5.2 asks us to build onto exercise 3.5.1 by appending the shape description string to the point, line, and circle description string

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
	Point p_1(1, 2);					//Initializing a point with coordinates (1,2)
	Point p_2(3, 4);					//Initializing a point with coordinates (3,4)

	cout << "Point 1:" << p_1.ToString() << endl;	//Testing modified ToString for Point
	cout << "Point 2:" << p_2.ToString() << endl;	//Testing modified ToString for Point

	Line l(p_1, p_2);					//Initiailizing a line that goes from (1,2) to (3,4)

	cout << l.ToString() << endl;					//Testing modified ToString for Line

	//Yes, now the ID is printed when printing a point or line

	Circle c(p_1, l);					//Initialzing a circle with a center of (1,2) and runs to (3,4)
	cout << c.ToString() << endl;					//Testing modified ToString for Circle

	//ID is also printed when printing a circle

	return 0;
}