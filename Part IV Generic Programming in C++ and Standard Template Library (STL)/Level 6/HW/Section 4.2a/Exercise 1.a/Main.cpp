//Exercise 4.2.1.a asks us to build onto exercise 3.6.2 by transforming the Array class for points created earlier into a template class

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
	int size;											//Declaring an integer for the size of the array
	cout << "Please enter a size for the array: ";		//Allowing user to decide the size	
	cin >> size;

	Array<Point> points(size);							//Creating an array of points

	for (int i = 0; i < size; i++)						//For 0<=i<size
	{
		cout << "Element " << i+1 << " = " << points[i] << endl;
	}
	//Should print (0,0), for each element

	//Testing SetElement
	int set_num;
	cout << "Please enter a nonnegative number less than the set size: ";
	cin >> set_num;
	try
	{
		Point p_1(1, 2);
		points.SetElement(set_num, p_1);
		cout << "Element " << set_num + 1 << " = " << points[set_num] << endl;
	}
	catch (ArrayException& error)
	{
		cout << error.GetMessage() << endl;
	}
	catch(...)
	{
		cout << "Unknown Error" << endl;
	}
	//Testing GetElement
	int get_num;
	cout << "Please enter a nonnegative number less than the set size: ";
	cin >> get_num;

	if (get_num < size)
	{
		cout << "Element " << get_num + 1 << " = ";
	}

	try
	{
		cout << points.GetElement(get_num) << endl;
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	cout << "Size of array = " << points.Size() << endl;

	Array<Point> arr_1 = points;		//Test assignment operator
	cout << "Assignment operator test: " << endl;

	for (int n = 0; n < size; n++)
	{
		cout << "Element " << n + 1 << " = " << arr_1[n] << endl;
	}

	//Square bracket operator has already been tested several times

	return 0;
}