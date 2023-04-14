/****************************************************
 * Author Jose Aponte                               *
 *                                                  *
 * Implementation for the Circle Class              *
 *                                                  *
 ***************************************************/

#include "Circle.hpp"


/**
 * Circle() -- Default Constructor
*/
Circle::Circle(){
    pCenter.X(0);
    pCenter.Y(0);
    m_radius = 1;
}

/**
 * ~Circle() -- Destructor
*/
Circle::~Circle(){}

 /**
 * Circle(const Point&, const double radius) -- Constructor
 * 
 * Parameter 
 *      Circle center Point and radius
 * Returns
 *      None
*/
Circle::Circle(const Point& P1, const double radius){
    pCenter = P1;
    m_radius = radius;
}

Circle::Circle(const double x, const double y, const double r){
    this->pCenter.X(x);
    this->pCenter.Y(y);
    m_radius = r;
}

 /**
 * void CenterPoint(Point&)
 * 
 * Parameter 
 *      Middle Point that will be modified
 * Returns
 *      Value of the middle point
*/
void Circle::CenterPoint(Point& middlePoint){
    middlePoint.X((pCenter.X()+m_radius)/2);
    middlePoint.Y((pCenter.Y()+m_radius)/2);
}

 /**
 * double Radius()
 * 
 * Parameter 
 *      None
 * Returns
 *      Value of the radius
*/
double Circle::Radius(){
    return m_radius;
}

 /**
 * double Diameter()
 * 
 * Parameter 
 *      None
 * Returns
 *      Value of the diameter
*/
double Circle::Diameter(){
    return 2*Radius();
}

/**
 * double Area()
 * 
 * LaTex equation
 *      area = \pi*r^{2}
 * Parameter 
 *      None
 * Returns
 *      Calculate the area
*/
double Circle::Area(){
    return (Radius()*Radius()*M_PI);
}

/**
 * double Circumference()
 * 
 * LaTex equation
 *      circumference = 2*\pi*r
 * Parameter 
 *      None
 * Returns
 *      Calculate the area
*/
double Circle::Circumference(){
    return (2*M_PI*Radius());
}

/**
 * string ToString() const
 * 
 * Parameters
 *      None
 * Returns
 *      The value the circle center point
 *      and the radius in string format
*/
string Circle::ToString() const{
    return "Circle with point ("+to_string(pCenter.X())
            +","+to_string(pCenter.Y())+")"+" with radius r= "
            +to_string(m_radius);
}
