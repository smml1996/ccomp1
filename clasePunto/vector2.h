#include "punto.h"
class V {
    private:
        Point first, second;
    public:
        V();
        V(Point &first, Point &second);
        float getFirstPx() const;
        float getSecondPx() const;
        float getFirstPy() const;
        float getSecondPy() const;
        void changeFirstP(const Point &p);
        void changeSecondP(const Point &p);
        void changeVec(const Point &first, const Point &second);
        Point getFirstP();
        Point getSecondP();

};
