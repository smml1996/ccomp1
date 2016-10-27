#if punto


#endif

#include <iostream>
# include "punto.h"
using namespace std;
Point::Point(Point &p){
   (*this).x = p.x; (*this).y = p.y;
    this->is_null = false;
}
Point::Point(int x_, int y_){
    (*this).x = x_;
    (*this).y = y_;
    this->is_null = false;
}
Point::Point(){
    this->x = 0; this->y =0;
    this->is_null = true;
}
 float Point::getX() const{
    return (*this).x;
}
 float Point::getY() const{
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

