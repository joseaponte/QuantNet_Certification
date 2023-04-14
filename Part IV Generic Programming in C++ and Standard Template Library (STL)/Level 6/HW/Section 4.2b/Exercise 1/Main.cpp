// Exercise 4.2.1.b asks us to build onto exercise 4.2.1.a by
// adding a static variable in the Array class that indicates 
// the default array size when using the default constructor

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
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;
	intArray1.DefaultSize(15);
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	//Values printed:
	//10
	//10
	//10
	//15
	//15
	//10

	//The first three lines are 10 because that is the default size we set for the static variable
	//The same holds for the last line of the doublearray
	//The middle lines change because of the line: intArray1.DefaultSize(15) since def_size is static
	//If we changed def_size to 9, all 10's in the code would be replaced with 9 while the 15's would remain the same

	return 0;
}