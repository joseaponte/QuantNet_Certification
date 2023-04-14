#include "Line.hpp"

Line::Line(){
    startPoint.X(0);
    startPoint.Y(0);
    endPoint.X(0);
    endPoint.Y(0);
}

Line::Line(const Point& Pointer1, const Point& Pointer2){
    startPoint = Pointer1;
    endPoint = Pointer2;
}

Line::Line(const Line& l){
    startPoint = l.startPoint;
    endPoint = l.endPoint;
}

Line::~Line(){}

void Line::P1(const Point& p_setter){
    startPoint = p_setter;
}

void Line::P2(const Point& p_setter){
    endPoint = p_setter;
}

Point Line::P1() const{
    return startPoint;
}

Point Line::P2() const{
    return endPoint;
}

string Line::ToString() const{
    return "Start-Point: ("+to_string(startPoint.X())+","+to_string(startPoint.Y())+
        ") and End-Point: ("+to_string(endPoint.X())+","+to_string(endPoint.Y())+")";
}

double Line::Length() {
    return startPoint.Distance(endPoint);
}