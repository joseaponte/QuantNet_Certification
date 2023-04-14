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
			if (this != &source)
			{
				Shape::operator=(source);			//Call the assignment operator of the Shape base class
				start_p = source.start_p;			//Copy start point
				end_p = source.end_p;				//Copy end point
			}

			return *this;
		}
		Line Line::operator+(const Line& L) const
		{
			return Line(start_p + L.start_p, end_p+L.end_p);
		}
		ostream& operator << (ostream& os, const Line& L)					//Send to ostream
		{
			os << "Line (" << L.Start_p() << "->" << L.End_p() << ")";	//Prints description of line
			return os;
		}

		std::string Line::ToString() const			//Using the str() function to retrieve the string from the string buffer
		{
			std::stringstream line_string;			//Using a std::stringstream object and the standard stream operators to create the string
			std::string s = Shape::ToString();		//Call the ToString() method of the Shape base class
			line_string << "Line goes from (" << start_p.X() << "," << start_p.Y() << ") to (" << end_p.X() << "," << end_p.Y() << ") - " << s;
			//Output in the form of "goes from (_,_) to (_,_)”
			return line_string.str();
		}

		double Line::Length() const					//Length of line function
		{
			return start_p.Distance(end_p);			//Finds length of line using distance function from Point Class
		}
		void Line::Draw() const						//Line Draw () function that simulates drawing by just printing some text
		{
			cout << "--------" << endl;				//Prints dashes to simulate a line
		}
	}
}