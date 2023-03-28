#include "Point.hpp"

Point::Point(){cout<<"Constructor"<<endl;};
Point::~Point(){cout<<"Destructor"<<endl;};

Point::Point(double x, double y){
    m_x = x;
    m_y = y;
    cout << "Overloaded Constructor" << endl;
}

void Point::SetX(double x){m_x = x;}
void Point::SetY(double y){m_y = y;}

double Point::GetX()const{return this->m_x;}
double Point::GetY()const{return this->m_y;}

string Point::ToString(){
    return "Point("+to_string(this->m_x)+","+to_string(this->m_y)+")";
}
 
double Point::DistanceOrigin(){
    return sqrt(pow(m_x,2)+pow(m_y,2));
}

double Point::Distance(const Point& P){
    return sqrt(pow((this->m_x)-(P.m_x),2)+pow((this->m_y)-(P.m_y),2));
}

