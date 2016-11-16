#include <iostream>
#include "polygons.h"
#include "stack.cpp"
#include "graph.h"
using namespace std;

#define MIN(a,b)((a)<(b)?(a): (b));

template <typename T>
T minimo(T a, T b){
    return a<b?a:b;
};

int main()
{
   /* cout<<minimo<int>(2,3)<<endl;
    cout<<MIN(7,5);
    cout<<endl;
*/
  /*  Rectangle *rect = new Rectangle(1,2,3,4);
    Triangle *tri = reinterpret_cast<Triangle *>(rect);
    Rectangle *rect2 = new Rectangle(1,2,3,4);
    Triangle *tri2 = dynamic_cast<Triangle *>(rect);
*/
  /*  Stack<int> a,b;
    a.push(1);
    a.push(2);
    b.push(1);b.push(2);
    Stack<int> c = a+b;

    for(;!c.is_empty_();){
        cout<<c.top()<<endl;
        c.pop();
    }*/

    vector<int> s,t;

    s.push_back(1);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);

    t.push_back(3);
    t.push_back(1);
    t.push_back(1);
    t.push_back(1);

    Graph g(t,s);
    cout<<g.numOutGoing(1)<<endl;

    const vector<int> ad= g.adjacent(1);

    for(int i = 0; i<ad.size(); i++){
        cout<<ad[i]<<endl;
    }
    return 0;
}
