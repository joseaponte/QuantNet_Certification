//Point.hpp is the header file for the Point class with private members for the x- and y-coordinates.

#ifndef POINT_HEADER		//If POINT_HEADER is not yet defined
#define POINT_HEADER		//Define it
#include "Shape.hpp"		//Include Shape header file

using namespace std;

namespace JoseAponte
{
	namespace CAD {
		class Point: public Shape
		{
		private:
			double m_x;									//Private member for the x-coordinate
			double m_y;									//Private member for the y-coordinate

		public:
			Point();									//Default Constructor
			~Point() {};								//Destuctor

			Point(const Point& p);						//Copy constructor
			Point(double x, double y);					//Alternate constructor that accepts two coordinates

			double X() const;							//Getter function for the x-coordinate
			double Y() const;							//Getter function for the y-coordinate

			Point operator - () const;					// Negate the coordinates.
			Point operator * (double factor) const;		// Scale the coordinates.
			Point operator + (const Point& p) const;	// Add coordinates.
			bool operator == (const Point& p) const;	// Equally compare operator.
			Point& operator = (const Point& source);	// Assignment operator.
			Point& operator *= (double factor);			// Scale the coordinates & assign.
			friend ostream& operator << (ostream& os, const Point& P); // Send to ostream.

			void X(double x)							//Inline (Default) Setter Function for X
			{
				m_x = x;
			}
			void Y(double y)							//Inline (Default) Setter Function for Y
			{
				m_y = y;
			}

			std::string ToString() const;				//Returns a string description of the point.

			double Distance() const;					//Calculate the distance to the origin (0, 0). Renamed to Distance from DistanceOrigin
			double Distance(const Point& p) const;		//Calculate the distance between two points.
		};

		inline double Point::X() const					//Inline (Normal) Getter Function for X
		{
			return m_x;
		}
		inline double Point::Y() const					//Inline (Normal) Getter Function for Y
		{
			return m_y;
		}
	}
}
#endif