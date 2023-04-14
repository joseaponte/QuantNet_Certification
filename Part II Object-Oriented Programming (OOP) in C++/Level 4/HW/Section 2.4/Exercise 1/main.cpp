// main.cpp 
//
// Test for Point, Line, and Circle class
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

	cout << "The point you've entered is: " << p1.ToString() << endl;		//Printing the description of the first point returned by the ToString() function

	Point p3 = -p1;												//Initializing p3 to be the negation of the first point

	cout << p1.ToString() << " * -1 = " << p3.ToString() << endl; //Testing the -operator by making sure the negation of first point is the output
	
	double factor;												//Factor will be the scalar used to multiply the first point by
	cout << "Please enter a factor to multiply the coordinates by:" << endl;
	cin >> factor;												//Initializing the factor using user input

	Point p4 = p1 * factor;										//Initializing p4 to be the first point multiplied by the factor
	cout << p1.ToString() << " * " << factor << " is " << p4.ToString() << endl;	//Testing the *operator to make sure the output is a multipled form of the first point
	
	double x_2, y_2;
	cout << "Enter another x-coordinate:" << endl;
	cin >> x_2;													//Asking the user for another x-coordinate using the std::cin object
	cout << "Enter another y-coordinate:" << endl;
	cin >> y_2;													//Asking the user for another y-coordinate using the std::cin object
	Point p2(x_2, y_2);											//Initializing the second point

	Point p5 = p1 + p2;											//Initializing p5 to be the point of the first two points added together
	cout << p1.ToString() << " + " << p2.ToString() << " = " << p5.ToString() << endl;	//Testing the +operator by making sure the output is the first two points added together

	double x_6, y_6;
	cout << "Enter another point to compare against the first point" << endl;
	cout << "x = ";
	cin >> x_6;													//Asking the user for another x-coordinate using the std::cin object
	cout << "y = ";
	cin >> y_6;													//Asking the user for another y-coordinate using the std::cin object
	Point p6(x_6, y_6);											//Initializing a 6th point to test the comparison operator

	p6 == p1;													//Testing the comparison operator

	p1 = p2;													//Testing the assingment operator
	cout << "Using the assignment operator, the first point was assigned " << p1.ToString() << ", the coordinates of the second point." << endl;

	p1 *= factor;
	cout << "Using the assign and scale operator, the first point has now been scaled to " << p1.ToString() << endl;

	cout << "A circle and radius will be formed with points 1 and 2 to test the line and cicle assignment operators." << endl;

	Line radius(p1, p2);		//Initializing a radius to the first and second points to test line assingment operator
	cout << "The radius " << radius.ToString() << endl;
	Line r = radius;			//Assigning a line r to the same points as the radius
	cout << "Using the assignment operator, a line was assigned the same points as the radius." << endl;
	cout << "Line r " << r.ToString() << endl;

	Circle C1(p1, radius);
	cout << "Circle 1 " << C1.ToString() << endl;
	Circle C2 = C1;			//Assigning another circle the same center and radius as C1
	cout << "Using the assignment operator, a circle was assigned the same center and radius as the first." << endl;
	cout << "Circle 2 " << C2.ToString() << endl;

	return 0;
}