#include "Point.hpp"

Point::Point(){cout<<"Constructor"<<endl;};
Point::~Point(){cout<<"Destructor"<<endl;};

Point::Point(double x, double y){
    m_x = x;
    m_y = y;
    cout << "Overloaded Constructor" << endl;
}

inline void Point::X(double x){m_x = x;}
inline void Point::Y(double y){m_y = y;}

double Point::X()const{return m_x;}
double Point::Y()const{return m_y;}

string Point::ToString() const{
    return "Point("+to_string(m_x)+","+to_string(m_y)+")";
}
 
double Point::Distance() const{
    return sqrt(pow(m_x,2)+pow(m_y,2));
}

double Point::Distance(const Point& P){
    return sqrt(pow((m_x)-(P.m_x),2)+pow((m_y)-(P.m_y),2));
}

