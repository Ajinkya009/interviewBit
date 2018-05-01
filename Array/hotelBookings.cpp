#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
	if(K == 0)
        return false;

    int N = arrive.size();
    
    vector<pair<int, int> > vec;
    for(int i = 0; i < N; ++i) {
        vec.push_back(make_pair(arrive[i], 1));
        vec.push_back(make_pair(depart[i], 0));
    }
     
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
    	cout<< vec[i].first << " " << vec[i].second << "\n";
    }
    int curActive = 0;
    int maxAns = 0;
    for (int i = 0; i < vec.size(); i++) {
       if (vec[i].second == 1) { // arrival
           curActive++;
           maxAns = max(maxAns, curActive);
        } else {
            curActive--;
        }
    }

    if (K >= maxAns) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr1[arr_i];
    }
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr2[arr_i];
    }
    int k;
    cin>>k;
 	bool a = hotel(arr1,arr2,k);
    return 0;
}