// main.cpp
//
// Dinamically Creating Objects
//
// Author Jose Aponte

#include "Point.hpp"		//Include Point Header File
#include "Line.hpp"			//Include Line Header File
#include "Circle.hpp"		//Include Circle Header File

using namespace std;

int main()
{
	double x_1, y_1;
	cout << "Enter an x-coordinate:" << endl;
	cin >> x_1;													//Asking the user for the x-coordinate using the std::cin object
	cout << "Enter a y-coordinate:" << endl;
	cin >> y_1;													//Asking the user for the y-coordinate using the std::cin object]
	
	Point* p1 = new Point;										//Create Point objects on the heap with new using the default constructor 
	Point* p_1 = new Point(x_1, y_1);							//Create Point objects on the heap with new using the constructor with coordinates
	Point* pt_1 = new Point(*p_1);								//Create Point objects on the heap with new using the copy constructor

	//Trying to call the Distance() function on the pointers and send the Point pointers to cout.
	cout << (*p1) << " to " << (*p_1) << " is " << (*p1).Distance(*p_1) << " units." << endl;
	cout << (*p_1) << " to " << (*pt_1) << " is " << (*p_1).Distance(*pt_1) << " units." << endl;

	delete p1;													//Deleting p1 created with new
	delete p_1;													//Deleting p_1 created with new
	delete pt_1;												//Deleting pt_1 created with new

	int arr_size;
	cout << "Please enter a size for an array of points: ";		//Asking user for size of array
	cin >> arr_size;											//Assigining user's input to arr_size

	//Trying to create an array on the stack using the entered size
	//Point arr_point[arr_size];
	
	//The following error codes were received:
	//failure was caused by a read of a variable outside its lifetime
	//Error	C2131	expression did not evaluate to a constant
	//Error(active)	E0028	expression must have a constant value

	//Creating the array on the heap using new
	Point* arr_point = new Point[arr_size];

	//Trying to create the array on the heap with other constructors:
	 
	//Testing constructor with coordinate arguments:
	//Point* arr_pt = new Point[arr_size](x_1, y_1);

	//The following error codes were received:
	//Error	C3074	an array cannot be initialized with a parenthesized initializer
	//Error(active)	E0391	a new - initializer may not be specified for an array

	//Testing copy constructor:
	//Point* array_p = new Point[arr_size](*arr_point);
	
	//The following error codes were received:
	//Error	C3074	an array cannot be initialized with a parenthesized initializer
	//Error(active)	E0391	a new - initializer may not be specified for an array

	delete [] arr_point;		//Deleting array of points, brackets required when deleting arrays

	return 0;
}