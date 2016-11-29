#include <vector>
using namespace std;

/*template<typename T> // now this is a template!
Stack<T> operator+ (const Stack<T> &lhs, const Stack<T> &rhs);*/
template <typename T>
class Stack{
    vector<T> values;

    public:
        void push(const T &val);
        void pop();
        T &top();
        bool is_empty_();

        template <typename W>
        friend Stack<W> operator +(Stack<W> s1,Stack<W> s2);

};
