#include <iostream>
#include <vector>
using namespace std;

int main(){
    int w,h; cin>>w>>h;

    char photo[h][w];char temp;
    for(int i = 0; i<h;i++){
        for(int j = 0; j<w;j++){
            cin>>temp;
            photo[i][j]= temp;
        }

    }

    char f[w][2*h];
    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            f[i][j*2]=photo[j][i];
            f[i][j*2+1]=photo[j][i];

        }

    }

    for(int i = 0; i<w;i++){
        for(int m = 0; m<2; m++){
        for(int j = 0; j<2*h;j++){

            cout<<f[i][j];
        }
        cout<<endl;}

    }

return 0;
}
