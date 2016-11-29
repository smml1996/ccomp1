#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int remain[1000000] = {0};
int main(){
int n, k;
cin>>n; cin>>k;

int temp; int nn=0;
for(int i = 0; i<n;i++){
    cin>>temp;
    if(remain[abs(temp)-1]==0){
        nn++;
        remain[abs(temp)-1] =1;
        if(temp%k==0){
            cout<<"Yes";
            return 0;
        }
    }
}

if(n<k-1){
    cout<<"No";
    return 0;
}
if(nn>=(k-1))cout<<"Yes";
else cout<<"No";
return 0;
}
