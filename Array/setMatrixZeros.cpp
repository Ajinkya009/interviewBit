#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setArray(vector<vector<int> > &a){
    vector < pair<int,int> > pairVec;
    for(int i=0;i<a.size();i++){
        for(int j=0; j<a[i].size(); j++){
            if(a[i][j]==0){
                pairVec.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=0;i<pairVec.size();i++){
        for(int p=0; p<a[pairVec[i].first].size(); p++){
            a[pairVec[i].first][p] = 0;
        }
        for(int p=0; p<a.size(); p++){
            a[p][pairVec[i].second] = 0;
        }
    }
}


int main() {
    int m,n,v;
    cin >> m;
    cin >> n;
    vector<vector<int> > a;
    
    for(int i = 0; i < m; i++){
        vector<int> b;
        for(int j=0; j<n;j++){
            cin >> v;
            b.push_back(v);
        }
        a.push_back(b);
    }
 	setArray(a);
    for(int i=0;i<a.size(); i++){
        for(int j=0; j<a[i].size();j++){
            cout<< a[i][j] << '\n';
        }
    }
    return 0;
}