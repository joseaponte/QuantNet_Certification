// Point.cpp
//
// Implementation file for Points in two dimensions
// 
// Author Jose Aponte


#include "Point.hpp"

/*----- Constructors -----*/
Point::Point(){};
Point::~Point(){};
Point::Point(double x, double y){
    m_x = x;
    m_y = y;
    //cout << "Overloaded Constructor" << endl;
}

Point::Point(const Point& P){
    m_x = P.m_x;
    m_y = P.m_y;
}

/*----- Accessing Functions -----*/
void Point::X(double x){m_x = x;}
void Point::Y(double y){m_y = y;}

double Point::X()const{return this->m_x;}
double Point::Y()const{return this->m_y;}

string Point::ToString(){
    return "("+to_string(this->m_x)+","+to_string(this->m_y)+")";
}
double Point::DistanceOrigin(){
    return sqrt(pow(m_x,2)+pow(m_y,2));
}
double Point::Distance(const Point& P) const{
    return sqrt(pow((this->m_x)-(P.m_x),2)+pow((this->m_y)-(P.m_y),2));
}

/*----- Operator Functions -----*/

Point Point::operator-() const{
    return Point(-m_x,-m_y);
}

Point Point::operator*(double factor) const{
    return Point(factor*m_x,factor*m_y);
}

Point Point::operator+(const Point& p) const{
    Point result;
    result.m_x = m_x+p.m_x;
    result.m_y = m_y+p.m_y;
    return result;
}

bool Point::operator==(const Point& p) const{
    bool result;
    return result = ((m_x==p.m_x)&&(m_y==p.m_y)?1:0);
}

Point& Point::operator=(const Point& source){
    m_x = source.m_x;
    m_y = source.m_y;
    return *this;
}

Point& Point::operator*=(double factor){
    m_x = factor*m_x;
    m_y = factor*m_y;
    return *this;
}
