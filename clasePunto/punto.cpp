#include "punto.h"
#include <iostream>

using namespace std;


Point::Point(Point &p){
   (*this).x = p.x; (*this).y = p.y;
    is_null = false;
}
Point::Point(int x_, int y_){
    (*this).x = x_;
    (*this).y = y_;
    is_null = false;
}
Point::Point(){
    this->x = 0; this->y =0;
    is_null = true;
}
 int Point::getX() const{
    return (*this).x;
}
 int Point::getY() const{
    return this->y;
}

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

void Point::printPoint(){
    cout<<"x: "<<this->x<<" y: "<<this->y<<endl;
}

void Point::modifyPoint(int x, int y){
    (*this).setX(x); (*this).setY(y);
}

void Point::flipNull(){
    this->is_null = !this->is_null;
}
bool Point::isNull(){
    return this->is_null;
}
