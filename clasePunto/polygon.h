#include "arrPoints.h"
class Polygon{
    protected:
        PointArray pa;
        static int nPolygons;
    public:
        Polygon( PointArray &pa);
        Polygon(Point points[], int arrl);
        Polygon();
        virtual double area() = 0;
        int getNumPolygons();
        int getNumSides();
        const Point * getPoints();
};



