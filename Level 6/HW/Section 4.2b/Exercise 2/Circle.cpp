
//Circle source file implements the Circle class 
// defined in the circle header file

#define	_USE_MATH_DEFINES		//Defining _USE_MATH_DEFINES for functionality of M_PI
#include "Circle.hpp"			//Include Circle Header File

using namespace std;

namespace JoseAponte
{
	namespace CAD
	{
		Circle::Circle() : Shape() {}															//Default Constructor w/Colon Syntax

		Circle::Circle(Point& P, Line& L) : Shape(), center(P), radius(L) {}						//Constructor that accepts a line and a point as parameters w/ Colon Syntax

		Circle::Circle(const Circle& C) : Shape(C), center(C.center), radius(C.radius) {}		//Copy constructor w/ Colon Syntax

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

		Circle& Circle::operator = (const Circle& source)	//Assignment Operator
		{
			if (this != &source)
			{
				Shape::operator=(source);					//Call the assignment operator of the Shape base class
				center = source.center;						//Copy center
				radius = source.radius;						//Copy radius
			}

			return *this;
		}
		ostream& operator << (ostream& os, const Circle& C)	// Send to ostream.
		{
			os << "has a center of " << C.center << " and a radius of " << C.radius.Length() << " units";
			return os;
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
		void Circle::Draw() const					//Circle Draw () function that simulates drawing by just printing some text
		{
			cout << "O" << endl;					//Prints an O to simulate a circle
		}

		std::string Circle::ToString() const		//ToString() function that returns a description of the circle
		{
			std::stringstream c_string;
			std::string s = Shape::ToString();		//Call the ToString() method of the Shape base class
			c_string << "Circle has a center of (" << center.X() << "," << center.Y() << ") and a radius of " << radius.Length() << " units - " << s;
			//Prints the center of the circle and the radius of the circle based on user input
			return c_string.str();
		}
	}
}