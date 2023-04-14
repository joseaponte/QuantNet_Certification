//Circle.hpp is the header file for the circle class, which has a center point and a radius as private data members

#ifndef CIRCLE_HPP				//If CIRCLE_HPP is undefined
#define CIRCLE_HPP				//Define it
#include "Line.hpp"				//Include Line Header File
#include "Point.hpp"			//And Point Header File

namespace JoseAponte
{
	namespace CAD
	{
		class Circle : public Shape
		{
		private:
			Point center;					//Private member for the center of the circle
			Line radius;					//Private member for the radius of the circle

		public:
			Circle();						//Default constructor
			Circle(const Point& P,const Line& L);		//Constructor that accepts a line and a point as parameters

			Circle(const Circle& C);		//Copy constructor
			~Circle();						//Destructor

			Point Center_Point() const;		//Center point of Point Class
			Line Radius() const;			//Radius of Line Class

			void Center_Point(Point& P);	//Center point of Circle
			void Radius(Line& L);			//Radius of Circle

			Circle& operator = (const Circle& c);	//Assignment Operator
			friend ostream& operator << (ostream& os, const Circle& C); // Send to ostream.


			double Diameter() const;		//Diameter function
			double Circumference() const;	//Circumference function
			double Area() const;			//Area function
			void Draw() const;				//Circle Draw () function that simulates drawing by just printing some text

			std::string ToString() const;	//ToString() function that returns a description of the circle
		};
	}
}
#endif