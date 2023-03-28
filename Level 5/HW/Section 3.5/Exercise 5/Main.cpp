//Exercise 3.5.5 asks us to build onto exercise 3.5.4 by making a Print() function for the Shape class that calls the ToString() and sends the result to the cout object

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

	Point p_1(1, 2);		//Initializing a point with coordinates (1,2)
	Point p_2(3, 4);		//Initializing a point with coordinates (3,4)

	p_1.Print();			//Testing Print function on a point
	p_2.Print();			//Testing Print function on a point

	Line l(p_1, p_2);		//Initializing a line that runs from (1,2) to (3,4)

	l.Print();				//Testing Print function on a line

	//Yes, it prints the right information even when point and line do not have the Print() function
	
	return 0;
}