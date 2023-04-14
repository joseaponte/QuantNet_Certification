// Line.hpp 
//
// Header file for the The Line class, which has a start - and an end - point 
// such that it has two Point objects as data members
//
// Author Jose Aponte

#ifndef LINE_HPP			//If LINE_HPP is undefined
#define LINE_HPP			//Define it

#include "Point.hpp"		//And include Point Header File


namespace JoseAponte{
	namespace CAD{
		class Line
		{
		private:
			Point start_p;						//Private member for the start point of the line
			Point end_p;						//Private member for the end point of the line

		public:
			Line() {};							//Default constructor(set the points to 0, 0)
			~Line() {};							//Destructor

			Line(Point&, Point&);				//Constructor with a start - and end - point.
			Line(const Line&);					//Copy constructor

			const Point& Start_p() const;		//Overloaded getter for the start-point.
			const Point& End_p() const;			//Overloaded getter for the end-point.

			void Start_p(const Point&);			//Overloaded setter for the start-point
			void End_p(const Point&);			//Overloaded setter for the end-point

			Line& operator = (const Line& );	//Assignment Operator for Line

			std::string ToString() const;		//ToString() function that returns a description of the line

			friend ostream& operator << (ostream& os, const Line &L); // Send to ostream.

			double Length() const;				//Length() function that returns the length of the line
		};
	}
}
#endif