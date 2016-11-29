#include <iostream>
#include <queue>

using namespace std;

int n, m;
char matrix [1000][1000];
int visited[1000][1000];

int delta [][2]= {{1,0},{0,1},{1,1},{1,-1},{-1,-1},{-1,1},{-1,0},{0,-1}};
bool is_valid(int f, int c){
    return f>=0 && c>=0 && f<n && c<m && matrix[f][c]!='#';
}

int bfs(){
    queue< pair<int, int> > spots;
    spots.push(make_pair(0,0));
    visited[0][0]= 0;
    pair<int, int> actual;
    int x, y; int result;
    while(!spots.empty()){
        actual = spots.front();
        spots.pop();
        for(int i = 0; i<7; i++){
            x = actual.second + delta[i][1]; y = actual.first + delta[i][0];
            if(is_valid(y, x)){
                if(visited[y][x]==-1){
                    spots.push(make_pair(y,x));
                    result = visited[y][x] = visited[actual.first][actual.second]+1;
                }
            }
        }
    }
    return result;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                cin>>matrix[i][j];
                visited[i][j]= -1;
            }
        }
        cout<<bfs()<<endl;

        for(int i  = 0; i< n; i++){
            for(int j = 0; j<m; j++){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}
