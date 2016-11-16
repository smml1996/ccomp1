#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007
using namespace std;

int result =0;
vector< vector< pair<string, int> > > results(4000);
void is_sequence(string t, string sub){
    int i = 0; int total =0;
    for(int j = 0; j<t.length(); j++){;
        if(sub.at(i)== t.at(j)){
            for(int m = j; m<t.length();m++){
                if(sub.at(i)==t.at(m))i++;
                if(i == sub.length()){total++; total%=MOD;i = 0; break;}
            }
            if(total==0)j= t.length();
        }

    }
    result+=total;
    results[sub.length()-1].push_back(make_pair(sub, total%=MOD));
}
int main(){
    string s, t; cin>>s; cin>>t; bool is_found = false;
    for(int i = 0; i<s.length();i++){
        for(int j = i; j<s.length();j++){
            is_found=false;//cout<<s.substr(i, j-i+1)<<endl;
            for(int m = 0; m<results[s.substr(i, j-i+1).length()-1].size();m++){
            //    cout<<"r:"<<results[s.substr(i, j-i+1).length()-1][m].first<<endl;
                if(results[s.substr(i, j-i+1).length()-1][m].first == s.substr(i, j-i+1)){
                    result+=results[s.substr(i, j-i+1).length()-1][m].second;result %= MOD; is_found = true; break;
                }

            }if(!is_found)is_sequence(t,s.substr(i,j-i+1));
            //cout<<result<<endl;
        }
    }
    for(int i = 0; i<results.size();i++){
        for(int j = 0; j<results[i].size();j++){
            cout<< results[i][j].first<<" "<<results[i][j].second<<endl;

        }

    }
    cout<<result<<endl;
}
