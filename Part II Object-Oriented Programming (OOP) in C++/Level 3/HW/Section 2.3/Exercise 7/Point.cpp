/****************************************************
 * Author Jose Aponte                               *
 *                                                  *
 * Implementation for the Point Class               *
 *                                                  *
 ***************************************************/

#include "Point.hpp"
#include <iostream>

/**
 * Point() -- Default Constructor
*/
Point::Point(){}

/**
 * ~Point() -- Destructor
*/
Point::~Point(){}

 /**
 * Point(double,double) -- Constructor
 * 
 * Parameter 
 *      Value of x- and y- parameter to be set
 * Returns
 *      None
*/
Point::Point(double x, double y){
    this->m_x = x;
    this->m_y = y;
}

 /**
 * void X(double)
 * 
 * Parameter 
 *      Value of x-parameter to be set
 * Returns
 *      None
*/
void Point::X(double x){this->m_x = x;}

 /**
 * void Y(double)
 * 
 * Parameter 
 *      Value of y-parameter to be set
 * Returns
 *      None
*/
void Point::Y(double y){this->m_y = y;}

/**
 * double X() const
 * 
 * Parameter 
 *      None
 * Returns
 *      Value of X-parameter
*/
double Point::X()const{return this->m_x;}

/**
 * double Y() const
 * 
 * Parameter 
 *      None
 * Returns
 *      Value of y-parameter
*/
double Point::Y()const{return this->m_y;}

/**
 * string ToString() const
 * 
 * Parameters
 *      None
 * Returns
 *      The value x- and y- parameter in string format
*/
string Point::ToString() const{
    return "Point("+to_string(m_x)+","+to_string(m_y)+")";
}

/* * 
 * double Distance() const
 * 
 * LaTex equation
 *      distance = \sqrt{(x-0)^2+(y-0)^2}
 * Parameters
 *      None
 * Returns 
 *      The distance between the point and origin(0,0)
 * */ 
double Point::Distance() const{
    return sqrt(pow(m_x,2)+pow(m_y,2));
}

/* * 
 * double Distance(const Point&P)
 * 
 * LaTex equation
 *      distance = \sqrt{(x_{2}-x_{1})^2+(y_{2}-y_{1})2}
 * Parameters
 *      Point P
 * Returns 
 *      The distance between Points
 * */ 
double Point::Distance(const Point& P){
    return sqrt(pow((m_x)-(P.m_x),2)+pow((m_y)-(P.m_y),2));
}

