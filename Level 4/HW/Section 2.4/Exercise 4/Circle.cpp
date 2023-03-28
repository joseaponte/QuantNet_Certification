// Circle.cpp
//
// Implementation file for Circle.
// 
// Author Jose Aponte

#define	_USE_MATH_DEFINES		//Defining _USE_MATH_DEFINES for functionality of M_PI
#include "Circle.hpp"			//Include Circle Header File

using namespace std;

Circle::Circle(Point& P, Line& L)			//Constructor that accepts a line and a point as parameters
{
	center = P;								//Center Point of circle
	radius = L;								//Radius of Circle
}

Circle::Circle(const Circle& C)				//Copy constructor
{
	center = C.center;						//Center of circle
	radius = C.radius;						//Radius of Circle
}

Point Circle::Center_Point() const			//Center point of Point Class
{
	return center;							//Returns Center of Circle
}
Line Circle::Radius() const					//Radius of Line Class
{
	return radius;							//Returns Radius of Circle
}

void Circle::Center_Point(Point& P)			//Center point of Circle
{
	center = P;
}

void Circle::Radius(Line& L)				//Radius of Circle
{
	radius = L;
}

Circle& Circle::operator = (const Circle& C)	//Assignment Operator
{
	center = C.center;
	radius = C.radius;
	return *this;
}

double Circle::Diameter() const				//Diameter of circle calculation function
{
	return (radius.Length() * 2);			//Diameter = length of radius * 2
}
double Circle::Circumference() const		//Circumference of circle calculation function
{
	return (radius.Length() * 2 * M_PI);	//Circumference = length of radius * 2 * pi
}
double Circle::Area() const					//Area of circle calculation function
{
	return (radius.Length() * radius.Length() * M_PI);		//Area = length of radius * length of radius * pi
}

std::string Circle::ToString() const		//ToString() function that returns a description of the circle
{
	std::stringstream c_string;
	c_string << "has a center of (" << center.X() << "," << center.Y() << ") and a radius of " << radius.Length() << " units";
	//Prints the center of the circle and the radius of the circle based on user input
	return c_string.str();
}

ostream& operator << (ostream& os, const Circle& C)
{
	os << C.ToString();
	return os;
}