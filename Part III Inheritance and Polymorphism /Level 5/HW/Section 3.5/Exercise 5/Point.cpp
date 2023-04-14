//Point source file implements the Point class defined in the header file

#include "Point.hpp"				//Include Point Header File

namespace JoseAponte
{
	namespace CAD
	{
		Point::Point() :Shape(), m_x(0), m_y(0) {}								//Default Constructor with Colon Syntax

		Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {}			//Constructor that accepts x- and y-coordinates with Colon Syntax

		Point::Point(const Point& P) : Shape(P), m_x(P.m_x), m_y(P.m_y) {}		//Copy Constructor with Colon Syntax

		// Member operator overloading
		Point Point::operator - () const					// Negate the coordinates.
		{
			return Point(-m_x, -m_y);						// Returns negative values of coordinates
		}
		Point Point::operator * (double factor) const		// Scale the coordinates.
		{
			return Point(factor * m_x, factor * m_y);		// Multiplies the coordinates by some factor
		}
		Point Point::operator + (const Point& p) const		// Add coordinates.
		{
			return Point(m_x + p.m_x, m_y + p.m_y);			// Adds coordinates of two points together
		}
		bool Point::operator == (const Point& p) const		// Equally compare operator.
		{
			bool b = 0;										//Initialize b to 0
			if (m_x == p.m_x && m_y == p.m_y)				//If both coordinate values equal each other
			{
				b = 1;										//Set b equal to 1
				cout << b << ", denoting the two points are equal." << endl;
			}
			else
			{
				cout << b << ", denoting the two points are not equal." << endl;
			}
			return b;
		}
		Point& Point::operator = (const Point& source)		// Assignment operator.
		{
			if (&source != this)
			{
				Shape::operator=(source);						//Call the assignment operator of the Shape base class
				m_x = source.m_x;								// Assigning x-coordinate
				m_y = source.m_y;								// Assigning y-coordinate
			}
			return *this;									// Operator changes the current object, so it can’t be const functions.To make it possible to chain, it must return the “this” object
		}
		Point& Point::operator *= (double factor)			// Scale the coordinates & assign.
		{
			m_x = factor * m_x;								// Scaling and assigning the x-coordinate
			m_y = factor * m_y;								// Scaling and assigning the y-coordinate
			return *this;									// Operator changes the current object, so it can’t be const functions.To make it possible to chain, it must return the “this” object
		}
		ostream& operator << (ostream& os, const Point& P)			//Send to ostream
		{
			os << "(" << P.m_x << "," << P.m_y << ")";				//Displays a point in the form (_,_)
			return os;
		}

		std::string Point::ToString() const							//Using the str() function to retrieve the string from the string buffer
		{
			std::stringstream m_string;								//Using a std::stringstream object and the standard stream operators to create the string
			std::string s = Shape::ToString();						//Call the ToString() method of the Shape base class
			m_string << "(" << m_x << "," << m_y << ") - " << s;	//Output in the form of "(x, y)”
			return m_string.str();
		}

		double Point::Distance() const								//Distance to origin function
		{
			return sqrt(m_x * m_x + m_y * m_y);						//Returns distance to origin, i.e. (x^2+y^2)^(1/2)
		}

		double Point::Distance(const Point& p) const				//Distance between two points function
		{
			double dis_x, dis_y;
			dis_x = m_x - p.m_x;									//Distance of first x-coordinate from second x-coordinate
			dis_y = m_y - p.m_y;									//Distance of first y-coordinate from second y-coordinate
			return sqrt(dis_x * dis_x + dis_y * dis_y);				//Returns distance between two points i.e. ((x_2-x_1)^2+(y_2-y_1)^2)^(1/2)
		}
		void Point::Draw()											//Point Draw () function that simulates drawing by just printing some text
		{
			cout << "." << endl;									//Prints a dot/period to simulate a point
		}
	}
}