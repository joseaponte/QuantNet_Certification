// main.cpp
//
// CAD and container Namespace
//
// Author Jose Aponte

#include "Circle.hpp"		//Include Circle Header File
#include "Array.hpp"		//Include Array Header File

using namespace std;
using JoseAponte::CAD::Point;			//Using the full namespace for Point class
using JoseAponte::CAD::Line;				//Using declaration for using a single class (Line)
using namespace JoseAponte::Containers;	//Using declaration for a complete namespace (Containers)
namespace Circle = JoseAponte::CAD;		//Using the Circle class by creating a shorter alias for the YourName::CAD namespace

int main()
{
	//This will just be a simple test of creating an displaying descriptions of the various classes
	double x_0, y_0;								//Declaring doubles for coordinates of a point
	cout << "Please enter an x-coordinate: ";
	cin >> x_0;										//Allowing user to decide x-coordinate of first point
	cout << "Please enter a y-coordinate: ";
	cin >> y_0;										//Allowing user to decide y-coordinate of first point
	Point p_0(x_0, y_0);							//Declaring and initializng 1st point
	
	cout << "Point 1 = " << p_0 << endl;			//Displaying description of first point

	double x_1, y_1;								//Declaring doubles for coordinates of another point
	cout << "Please enter another x-coordinate: ";
	cin >> x_1;										//Allowing user to decide x-coordinate of second point
	cout << "Please enter another y-coordinate: ";
	cin >> y_1;										//Allowing user to decide y-coordinate of second point
	Point p_1(x_1, y_1);							//Declaring and initializng 2nd point

	cout << "Point 2 = " << p_0 << endl;			//Displaying description of second point

	Line l_0(p_0, p_1);								//Declaring and initializing a line with p_0 and p_1 as its points

	cout << "Line 1 " << l_0 << endl;				//Displaying description of the line

	JoseAponte::CAD::Circle c_0(p_0, l_0);			//Declaring and initializing a cirlce with p_0 as its center and l_0 as its radius

	cout << "Circle 1 " << c_0 << endl;				//Displaying description of the circle

	int arr_size;									//Declaring an integer for the size of an array
	cout << "Please enter an array size: ";			//Allowing user to decide arr_size
	cin >> arr_size;

	Array arr_0(arr_size);							//Declaring an array of the given size by user
	int i;											//Declaring an integer for iterations of a loop

	for (i = 0; i < arr_size; i++)	//For i <= 0 < arr_size
	{
		if (i == 0)								//If i = 0
		{
			x_0 = i;							//Set x = 0
			y_0 = i;							//Set y = 0
			Point p_2(x_0, y_0);				//For simplicity, p_2 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_2;						//Set 1st element to p_2
			cout << "Constructor w/ Size Argument Test: " << "{" << arr_0[i] << ",";
			//Output Constructor w/ Size Argument Test: {(0,0),
		}
		else if (i == arr_size - 1)				//If i = arr_size
		{
			x_0 = i;							//Set x = arr_size
			y_0 = i;							//Set y = arr_size
			Point p_2(x_0, y_0);				//For simplicity, p_2 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_2;						//Set 9th element to p_2
			cout << arr_0[i] << "}\n";			//Output (arr_size, arr_size)}
		}
		else
		{
			x_0 = i;							//Otherwise, set x = i
			y_0 = i;							//Set y = i
			Point p_2(x_0, y_0);				//For simplicity, p_2 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_2;						//Set ith element to p_2
			cout << arr_0[i] << ",";			//Output (i,i)
		}
	}

	return 0;
}