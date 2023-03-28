// Circle.hpp 
//
// Header file for the circle class, which has a 
// center point and a radius as private data members
//
// Author Jose Aponte

#ifndef CIRCLE_HPP				
#define CIRCLE_HPP			

#include "Line.hpp"				
#include "Point.hpp"			

namespace JoseAponte{
	namespace CAD{
		class Circle
		{
		private:
			Point center;						//Private member for the center of the circle
			Line radius;						//Private member for the radius of the circle

		public:

		/*----- Constructors -----*/
			Circle() {};						//Default constructor
			Circle(Point&, Line&);				//Constructor that accepts a line and a point as parameters

			Circle(const Circle&);				//Copy constructor
			~Circle() {};						//Destructor

		/*----- Accessing Functions -----*/
			Point Center_Point() const;			//Center point of Point Class
			Line Radius() const;				//Radius of Line Class
			void Center_Point(Point&);			//Center point of Circle
			void Radius(Line&);					//Radius of Circle
			double Diameter() const;			//Diameter function
			double Circumference() const;		//Circumference function
			double Area() const;				//Area function
			std::string ToString() const;		//ToString() function that returns a description of the circle
			friend ostream& operator << (ostream& os, const Circle& C); // Send to ostream.

		/*----- Operator Functions -----*/
			Circle& operator = (const Circle&);	//Assignment Operator
		};
	}
}
#endif