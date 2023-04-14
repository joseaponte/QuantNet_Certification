//Line.hpp is the header file for the The Line class, which has a start - and an end - point such that it has two Point objects as data members

#ifndef LINE_HPP			//If LINE_HPP is undefined
#define LINE_HPP			//Define it
#include "Point.hpp"		//And include Point Header File

namespace JoseAponte
{
	namespace CAD
	{
		class Line : public Shape
		{
		private:
			Point start_p;						//Private member for the start point of the line
			Point end_p;						//Private member for the end point of the line

		public:
			Line();								//Default constructor
			~Line();							//Destructor

			Line(const Point& P1, const Point& P2);			//Constructor with a start - and end - point.
			Line(const Line& L);							//Copy constructor

			const Point& Start_p() const;		//Overloaded getter for the start-point.
			const Point& End_p() const;			//Overloaded getter for the end-point.

			void Start_p(const Point& startp);	//Overloaded setter for the start-point
			void End_p(const Point& endp);		//Overloaded setter for the end-point

			Line& operator = (const Line& source);	//Assignment Operator for Line
			friend ostream& operator << (ostream& os, const Line& L); // Send to ostream.

			std::string ToString() const;		//ToString() function that returns a description of the line

			double Length() const;				//Length() function that returns the length of the line
		};
	}
}
#endif