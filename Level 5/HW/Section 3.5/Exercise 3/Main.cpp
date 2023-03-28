//Exercise 3.5.3 asks us to build onto exercise 3.5.2 by declaring Shape's destructor as virtual and testing the following program

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
	//Testing the supplied code to see if the proper destructors are called
	Shape* shapes[3];			//Shape pointer array with the elements
	shapes[0] = new Shape;		//First element is a shape
	shapes[1] = new Point;		//Second element is a point
	shapes[2] = new Line;		//Third element is a lien

	for (int i = 0; i != 3; i++) delete shapes[i];		//For 0<=i<3, delete the ith element

	//Prior to declaring the Shape/Base Class destructor virtual, only the Shape destructor is called (not the proper ones)
	//After declaring the Shape/Base Class destructor virtual, the proper destructors appear to be called


	return 0;
}