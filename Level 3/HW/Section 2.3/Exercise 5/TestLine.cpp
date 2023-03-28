#include <iostream>
#include "Line.hpp"

using namespace std;

int main(){
    cout << "Default Constructor" << endl;
    Line lineTestingDefault;
    cout << lineTestingDefault.ToString() << endl;
    Point pBeginOverloading(2,3);
    Point pEndOverloading(5,-3);
    Line lineTestingOverloading(pBeginOverloading,pEndOverloading);
    cout <<"Overloading Constructor" << endl;
    cout << lineTestingOverloading.ToString() << endl;

    Point pBeginSetter(1,1);
    Point pEndSetter(7,5);
    lineTestingDefault.P1(pBeginSetter);
    lineTestingDefault.P2(pEndSetter);
    cout <<"Setters" << endl;
    cout << lineTestingDefault.ToString() << endl;

    cout <<"Getters"<< endl;
    Point pGetterP1 = lineTestingDefault.P1();
    Point pGetterP2 = lineTestingDefault.P2();
    cout << "Start-Point: (" << pGetterP1.X() <<","<<pGetterP1.Y()<<")"<< endl;
    cout << "End-Point: (" << pGetterP2.X() <<","<<pGetterP2.Y()<<")"<< endl;

    cout << "Distance Between Points" << endl;
    cout << lineTestingDefault.Length() << endl;

    return 0;
}