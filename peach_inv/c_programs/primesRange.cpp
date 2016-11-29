#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> primes;
void sieve(int n){
    static bool is_primes[100000];
    static int i =2;
    for(;i<=floor(sqrt(n));i++){
        if(!is_primes[i]){
            primes.push_back(i);
            for(int j = i+i; j<=100000;j+=i){is_primes[j]=true;}
        }
    }
}

bool is_prime(int a){

    if(a ==2)return true;
    if(a==1)return false;
    for(int h = 0; primes[h]*primes[h]<=a && h<primes.size();h++){
        if(a%primes[h]==0)return false;
    }
    return true;
}

int main(){
    int tc; cin>>tc;
    int a, b;
    while(tc--){
        cin>>a; cin>>b;
        sieve(b);
        for(int m = a; m<=b;m++){
            if(is_prime(m))cout<<m<<endl;
        }

        cout<<endl;
    }

return 0;
}
