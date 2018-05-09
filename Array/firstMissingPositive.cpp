/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissing(vector<int> &a){
    sort(a.begin(),a.end());
    for(int i=0; i<a.size()-1; i++){
        if(a[i+1]!=a[i]+1){
            return a[i]+1;
        }
    }
}


int main() {
    int m,n,v;
    cin >> m;
    vector<int> a;

    for(int i = 0; i < m; i++){
        cin >> n;
        a.push_back(n);
    }
 	v = findMissing(a);
    for(int i=0;i<a.size(); i++){
        cout<< a[i] << '\n';
    }
    cout << v;
    return 0;
}
