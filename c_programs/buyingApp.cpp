#include <iostream>
#include <vector>

using namespace std;

vector<int> prices;
int get_min(int friends, int kg, vector< vector<int> > &minimums){
    if(kg==1){
        minimums[1][1]=prices[1];
        return minimums[1][1];
    }

    if(minimums[kg][1]==0)get_min(friends, kg-1, minimums);
    minimums[kg][1]= prices[kg];
};


int main(){
    int tc; cin>>tc;
    int kg, friends; int temp;
    while(tc--){
        vector< vector<int> > minimums (102, vector<int>(102,0));
            prices.clear();
            prices.push_back(0);
            cin>>friends>>kg;
            for(int i = 0; i<kg; i++){
                cin>>temp; prices.push_back(temp);
            }

        cout<<get_min(friends, kg, minimums);
    }



return 0;
}
