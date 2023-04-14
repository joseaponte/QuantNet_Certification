//VariantVisitor.hpp is the header file for the the VariantVisitor class, which has data members for the x- and y-offset that are set in the constructor

#ifndef VARIANTVISITOR_HPP
#define VARIANTVISITOR_HPP

#include "boost/variant.hpp"
#include "Circle.hpp"

using namespace JoseAponte::CAD;

class VariantVisitor : public boost::static_visitor<void>
{
private:
	double m_dx;					//Data member for the x-offset
	double m_dy;					//Data member for the y-offset

public:
	VariantVisitor();									//Default Constructor
	~VariantVisitor() {};								//Destructor

	VariantVisitor(const VariantVisitor& VV);			//Copy Constructor
	VariantVisitor(double dx, double dy);				//Constructor that accepts two doubles as parameters to set the offset data members
	VariantVisitor(double offset);						//Constructor that accepts a single double as a parameter for the offset data members

	VariantVisitor operator = (VariantVisitor& source); //Assignment Operator
	void operator () (Point& p) const;					//Visit a point
	void operator () (Line& l) const;					//Visit a line
	void operator () (Circle& c) const;					//Visit a circle

	double DX() const;									//Getter for dx data member
	double DY() const;									//Getter for dy data member

	void DX(double x_off);								//Setter for dx data member
	void DY(double y_off);								//Setter for dy data member
};
#endif // !VARIANTVISITOR_HPP