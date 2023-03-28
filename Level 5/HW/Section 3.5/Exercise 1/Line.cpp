//Line source file implements the Line class defined in the line header file

#include "Line.hpp"						//Include Line Header File

namespace JoseAponte
{
	namespace CAD
	{
		Line::Line() : Shape() {}															//Default Constructor

		Line::Line(const Point& P1, const Point& P2) : Shape(), start_p(P1), end_p(P2) {}	//Line Constructor that accepts a start & end point w/ Colon Syntax

		Line::Line(const Line& L) : Shape(L), start_p(L.start_p), end_p(L.end_p) {}			//Copy constructor w/ Colon Syntax

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
			if (&source != this)
			{
				Shape::operator=(source);			//Call the assignment operator of the Shape base class
				start_p = source.start_p;			//Copy start point
				end_p = source.end_p;				//Copy end point
			}

			return *this;
		}
		ostream& operator << (ostream& os, const Line& L)	//Send to ostream
		{
			os << "goes from " << L.start_p << " to " << L.end_p;	//Displays the points of the line
			return os;
		}

		std::string Line::ToString() const			//Using the str() function to retrieve the string from the string buffer
		{
			std::stringstream line_string;			//Using a std::stringstream object and the standard stream operators to create the string
			line_string << "Line goes from (" << start_p.X() << "," << start_p.Y() << ") to (" << end_p.X() << "," << end_p.Y() << ")";
			//Output in the form of "goes from (_,_) to (_,_)”
			return line_string.str();
		}

		double Line::Length() const					//Length of line function
		{
			return start_p.Distance(end_p);			//Finds length of line using distance function from Point Class
		}
	}
}