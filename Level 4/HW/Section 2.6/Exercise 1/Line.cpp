// Line.cpp
//
// Implementation file for Line class
// 
// Author Jose Aponte

#include "Line.hpp"						//Include Line Header File

namespace JoseAponte{
	namespace CAD{
		Line::Line(Point& P1, Point& P2)		//Line Constructor that accepts a start & end point
		{
			start_p = P1;						//Start point of line
			end_p = P2;							//End point of line
		}

		Line::Line(const Line& L)				//Copy constructor
		{
			start_p = L.start_p;				//Start point
			end_p = L.end_p;					//Start point
		}

		const Point& Line::Start_p() const		//Getter for start point
		{
			return start_p;
		}

		const Point& Line::End_p() const		//Getter for end point
		{
			return end_p;
		}

		void Line::Start_p(const Point& startp)		//Setter function for start point
		{
			start_p = startp;
		}
		void Line::End_p(const Point& endp)			//Setter function for end point
		{
			end_p = endp;
		}

		Line& Line::operator = (const Line& source)	//Assignment Operator for Line
		{
			start_p = source.start_p;
			end_p = source.end_p;
			return *this;
		}

		std::string Line::ToString() const			//Using the str() function to retrieve the string from the string buffer
		{
			std::stringstream line_string;			//Using a std::stringstream object and the standard stream operators to create the string
			line_string << "goes from (" << start_p.X() << "," << start_p.Y() << ") to (" << end_p.X() << "," << end_p.Y() << ")";
			return line_string.str();
		}

		double Line::Length() const					//Length of line function
		{
			//return this->start_p.D
			return start_p.Distance(end_p);			//Finds length of line using distance function from Point Class
		}

		ostream& operator << (ostream& os, const Line& L)
		{
			os << L.ToString();
			return os;
		}
	}
}