//Exercise 3.4.1 asks us to build onto exercise 2.6.1 by adding Colon Syntax to our classes' constructors and then testing how many times each (including the assignment operator) is called 

#include "Circle.hpp"		//Include Circle Header File
#include "Array.hpp"		//Include Array Header File

using namespace std;
using JoseAponte::CAD::Point;			//Using the full namespace for Point class
using JoseAponte::CAD::Line;				//Using declaration for using a single class (Line)
using namespace JoseAponte::Containers;	//Using declaration for a complete namespace (Containers)
namespace Circle = JoseAponte::CAD;		//Using the Circle class by creating a shorter alias for the YourName::CAD namespace

int main()
{
	Line l(Point(1, 2), Point(2, 3));

	//Prior to adding colon syntax:
	//Point 2 Coordinates Constructor was called twice
	//Point Default Constuctor was called twice
	//Point Copy Constructor was called 0 times
	//Point assignment operator was called twice 
	//And point destructor was called 4 times

	//After adding colon syntax:
	//Point 2 Coordinates Constructor was called twice
	//Point Default Constuctor was called 0 times
	//Point Copy Constructor was called twice
	//Point assignment operator was called 0 times
	//And point destructor was called 4 times

	return 0;
}