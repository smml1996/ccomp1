#include "triangle.h"
Triangle::Triangle(Point &a, Point &b, Point &c):Polygon(updateConstructorPoints(a,b,c),3) {

    nPolygons++;
}

double Triangle::area() {
    double side1, side2, side3;
    side1 = sqrt(pow(*(this->pa).get_p().getX()-*((this->pa).get_p()+1).getX())+pow(*(this->pa).get_p().getY()-*((this->pa).get_p()+1).getY()));
    side2 = sqrt(pow(*((this->pa)+1).get_p().getX()-*((this->pa).get_p()+2).getX())+pow(*((this->pa)+1).get_p().getY()-*((this->pa).get_p()+2).getY()));
    side3 = sqrt(pow(*(this->pa).get_p().getX()-*((this->pa).get_p()+2).getX())+pow(*(this->pa).get_p().getY()-*((this->pa).get_p()+2).getY()));
    double midPerimeter = (side1+side2+side3)/2.0;
    return sqrt(midPerimeter*(midPerimeter-side1)*(midPerimeter-side2)*(midPerimeter-side3));
}