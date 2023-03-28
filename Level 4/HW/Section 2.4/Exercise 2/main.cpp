// main.cpp
//
// Test OSTREAM for Circle, Line, and Point class
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
	Point p1(x_1, y_1);											//Initializing the first point

	cout << "The point you've entered is: " << p1 << endl;		//Printing the description of the first point

	cout << p1 << " * -1 = " << -p1 << endl;					//Testing the - operator

	double factor;												//Factor will be the scalar used to multiply the first point by
	cout << "Please enter a factor to multiply the coordinates by:" << endl;

	cin >> factor;												//Initializing the factor using user input

	cout << p1 << " * " << factor << " is " << p1 * factor << endl;	//Testing the * operator by making sure the output is a multipled form of the first point

	double x_2, y_2;
	cout << "Enter another x-coordinate:" << endl;
	cin >> x_2;													//Asking the user for another x-coordinate using the std::cin object
	cout << "Enter another y-coordinate:" << endl;
	cin >> y_2;													//Asking the user for another y-coordinate using the std::cin object
	Point p2(x_2, y_2);											//Initializing the second point

	cout << p1 << " + " << p2 << " = " << p1 + p2 << endl;		//Testing the + operator by making sure the output is the first two points added together

	double x_3, y_3;
	cout << "Enter another point to compare against the first point" << endl;
	cout << "x = ";
	cin >> x_3;													//Asking the user for another x-coordinate using the std::cin object
	cout << "y = ";
	cin >> y_3;													//Asking the user for another y-coordinate using the std::cin object
	Point p3(x_3, y_3);											//Initializing a 6th point to test the comparison operator


	p3 == p1;													//Testing the comparison operator
	//Will output 1, and following message if the two points are equal
	//Will output 0, and a different message if they don't equal

	p1 = p2;													//Assigning the coordinates of p2 to p1

	cout << "Using the assignment operator, the first point was assigned " << p1 << ", the coordinates of the second point." << endl;
	//Testing the assignment operator, should display the same coordinates as the second point but using the first point

	p1 *= factor;												//Assigning and scaling p1

	cout << "Using the assign and scale operator, the first point has now been scaled to " << p1 << endl;
	//Testing the scale and assign operator, should scale and assign new values to the first point

	cout << "A circle and radius will be formed with points 1 and 2 to test the line and cicle assignment operators." << endl;

	Line radius(p1, p2);		//Initializing a radius to the first and second points to test line assingment operator
	cout << "The radius " << radius << endl;
	Line r = radius;			//Assigning a line r to the same points as the radius
	cout << "Using the assignment operator, a line was assigned the same points as the radius." << endl;
	cout << "Line r " << r << endl;
	//Testing the line assignment operator, the description of r and the radius should be the same.

	Circle C1(p1, radius);		//Initializing a circle with a center at p1 and a radius that runs to p2
	cout << "Circle 1 " << C1 << endl;
	Circle C2 = C1;			//Assigning another circle the same center and radius as C1
	cout << "Using the assignment operator, a circle was assigned the same center and radius as the first." << endl;
	cout << "Circle 2 " << C2 << endl;
	//Testing the circle assignment operator, the description of C1 and C2 should be the same.

	return 0;
}