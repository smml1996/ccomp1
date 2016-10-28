#include <iostream>
#define is_positive(a) a>0

using namespace std;
int schedule[days]; int hours[subjects];
int get_minimum(int start, int acc){

}
int main(){
    int days, subjects;
    for(int i = 0; i<days; i++)cin>>schedule[i];
    for(int i = 0; i<subjects;i++)cin>>hours[i];
    int studied = 0;
    cout<<get_minimum(0, studied);
return 0;
}
