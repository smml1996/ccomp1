#include<iostream>
#include<vector>
using namespace std;

vector<int> results(101, -1);

void swapp(int &a, int &b){
    int temp =a;
    a=b;
    b=temp;
}


int fib(int n){
    if(n <=0){
        return results[0];
    }
    if(n==1)return 1;
    if(results[n-1]<0)fib(n-1);
    results[n]= results[n-2]+results[n-1];
    return results[n];

}

int main(){
    int a = 10, b=11;

    swapp(a,b); cout<<a<<endl<<b;

return 0;
}
