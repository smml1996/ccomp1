#include "polygon.h"
class Rectangle:public Polygon{
public:
    Rectangle(const Point &a, const Point &b);
    Rectangle(int x1,int y1, int x2,int y2);
    double area();
};