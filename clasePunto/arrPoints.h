#include "punto.h"

class PointArray {
    private:
        int s;
        Point *(point[]);
        bool realloc(int si);
    public:
        PointArray(const Point points[], const int s);
        PointArray(const PointArray &pv);
        PointArray();
        void push_b(const Point &p);
        void insertar(const int index, const Point &p);
        const int get_size() const;
        void clear_arr();
        void print_arr();
};

