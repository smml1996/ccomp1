#include "vector2.h"
V::V(){
    this->first = Point();
    this->second = Point();
}

V::V(Point &f, Point &s){
    this->first = Point(f);
    this->second = Point(s);
}

float V::getFirstPx() const{
    return (this->first).getX();
}

float V::getFirstPy() const{
    return (this->first).getY();
}
float V::getSecondPx() const{
    return (this->second).getY();
}
float V::getSecondPy() const{
    return (this->second).getY();
}

void V::changeFirstP(const Point &p){
    (this->first).modifyPoint(p.getX(), p.getY());
}

void V::changeSecondP(const Point &p){
    (this->second).modifyPoint(p.getX(), p.getY());
}

void V::changeVec(const Point &f, const Point &s){
    this->changeFirstP(f);
    this->changeSecondP(s);
}

Point V::getFirstP(){
    return this->first;
}
 Point V::getSecondP(){
    return this->second;
}

