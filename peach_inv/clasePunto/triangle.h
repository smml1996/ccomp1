#include "polygon.h"
class Triangle: public Polygon{
public:
    Triangle(Point &a, Point &b, Point &c);
    double area();
};