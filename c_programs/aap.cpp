#include <iostream>
#include <vector>

using namespace std;

vector<int> sequence;
static int i = 0;int n;
int result(){
    int cont = 2;
    int q = i+1<n && i+2%2!=0? sequence[i]-sequence[i+1]: sequence[i+1]-sequence[i];
    i+=2; int temp;
    for(; i<n; i++){
        temp = i+2%2==0? sequence[i-1] + q: sequence[i-1]-q;
        if(temp!=sequence[i])return cont;
        cont++;
    }
    return cont;
}

int main(){
    cin>>n;
    int temp; int ans=-1;

    if(i>=n){
        cout<<n<<endl;
        return 0;
    }
    for(int m = 0;m<n; m++){
        cin>>temp;
        sequence.push_back(temp);
    }

    while(n-i+1>2){
        if(ans==-1)ans = result();
        else ans= max(ans, result());
    }
    cout<<ans<<endl;
    return 0;
}
