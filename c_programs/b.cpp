#include <iostream>

using namespace std;


int main(){
    int n ; cin>>n;
    int pizzas[n];
    for(int i = 0; i<n; i++){
        cin>>pizzas[i];
    }
    int active = 0;
    for(int i = 0; i<n; i++){
        if(pizzas[i] ==0  && active>0 ){
            cout<<"NO";
            return 0;
        }else{
            if(active>0){

                pizzas[i]-=active;
                active =0;
                if(pizzas[i]%2!=0){
                    active=1;
                }
            }else{

                if(pizzas[i]%2!=0){
                    active =1;
                }
            }

        }
    }
    if(active>0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";

return 0;
}
