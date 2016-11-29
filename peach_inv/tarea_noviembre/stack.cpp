#include "stack.h"
#include <vector>
using namespace std;


template <typename T>
void Stack<T>::push(const T &val){
    values.push_back(val);
}

template <typename T>
bool Stack<T>::is_empty_(){return values.size()==0;}


template <typename T>
void Stack<T>::pop(){values.erase(values.end()-1);}

template <typename T>
T &Stack<T>::top(){return values[values.size()-1];}

template <class T>
Stack<T> operator +(Stack<T> s1,Stack<T> s2){
    Stack<T> * result = new Stack<T>;
    for( ;!s1.is_empty_();){
        result->push(s1.top()+s2.top());
        s1.pop(); s2.pop();
    }
    return *result;
}
