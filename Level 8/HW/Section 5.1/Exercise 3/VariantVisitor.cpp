//VariantVisitor source file implements the Point class defined in the header file

#include "VariantVisitor.hpp"

VariantVisitor::VariantVisitor() : boost::static_visitor<void>(), m_dx(1.0), m_dy(1.0) {}												//Default Constructor

VariantVisitor::VariantVisitor(const VariantVisitor& VV) : boost::static_visitor<void>(VV), m_dx(VV.m_dx), m_dy(VV.m_dy) {} 			//Copy Constructor
VariantVisitor::VariantVisitor(double dx, double dy) : boost::static_visitor<void>(), m_dx(dx), m_dy(dy) {}								//Constructor that accepts two doubles as parameters to set the offset data members
VariantVisitor::VariantVisitor(double offset) : boost::static_visitor<void>(), m_dx(offset), m_dy(offset) {}							//Constructor that accepts a single double as a parameter for the offset data members

VariantVisitor VariantVisitor::operator=(VariantVisitor& source)
{
	if (this != &source)
	{
		boost::static_visitor<void>::operator = (source);		//Call the base class assignment operator
		m_dx = (source).m_dx;									//Assign m_dx to that of the source's
		m_dy = (source).m_dy;									//Assign m_dy to that of the source's
	}

	return (*this);
}

void VariantVisitor::operator()(Point& p) const					//For Point, create an operator () that changes the coordinates of the Point
{
	p.X(p.X() + m_dx);											//Add x-offset to the x-coordiante
	p.Y(p.Y() + m_dy);											//Add y-offset to the y-coordinate
}

void VariantVisitor::operator()(Line& l) const					//For Line, create an operator () that changes the coordinates of the Line
{
	l.Start_p(l.Start_p() + Point(m_dx, m_dy));					//Add x- and y-offset to the start point of the line
	l.End_p(l.End_p() + Point(m_dx, m_dy));						//Add x- and y-offset to the end point of the line
}

void VariantVisitor::operator()(Circle& c) const				//For Circle, create an operator () that changes the coordinates of the Circle
{
	c.Center_Point(c.Center_Point() + Point(m_dx, m_dy));				//Add x- and y-offset to the center of the circle
	c.Radius(c.Radius() + Line(Point(m_dx, m_dy),Point(m_dx, m_dy)));	//Add x- and y-offset to start and end points of the circle
}

double VariantVisitor::DX() const								//Getter for m_dx data member
{
	return m_dx;												//Return m_dx data member
}
double VariantVisitor::DY() const								//Getter for m_dy data member
{
	return m_dy;												//Return m_dy data member
}

void VariantVisitor::DX(double x_off)							//Setter for m_dx data member
{
	m_dx = x_off;												//Set m_dx data member to x_off
}
void VariantVisitor::DY(double y_off)							//Setter for m_dy data member
{
	m_dy = y_off;												//Set m_dy data member to y_off
}