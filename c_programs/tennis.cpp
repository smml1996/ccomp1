#include <iostream>

using namespace std;

int get_msb(int n){
    int m = 0;
    while(n>0){
        n = n>>1;
        m++;
    }
    m-=1;
    return m;
}
int main(){
    int n, b, p; cin>>n>>b>>p;

    int c_n = n;
    int result =0 ;int temp;
    while(n>1){
        temp = get_msb(n);
        result+= temp*b*(2) +temp;
        n-=temp;
    }

    cout<<result<<" "<<c_n*p;






return 0;
}
