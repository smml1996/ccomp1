#include "vector2.h"
class arrVec {
     private:
        int s;
        V *vec;
        bool realloc(int si);
    public:
        arrVec(const V vectors[], const int s);
        arrVec(const arrVec &av);
        arrVec();
        void push_b( V &v);
        void insertar(const int index,V &v);
        const int get_size() const;
        void clear_arr();
        void print_arr();
        void remove_vec(const int position);
        V * get_p() const;
};
