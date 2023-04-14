#include "Point.hpp"

Point::Point(){};
Point::~Point(){};

void Point::SetX(double x){m_x = x;}
void Point::SetY(double y){m_y = y;}

double Point::GetX()const{return this->m_x;}
double Point::GetY()const{return this->m_y;}

string Point::ToString(){
    string pointString = "Point("+to_string(this->m_x)+","+to_string(this->m_y)+")";
    return pointString;
}

