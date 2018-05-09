/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking.
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input :
	Arrivals :   [1 3 5]
	Departures : [2 6 8]
	K : 1

Return : False / 0

At day = 5, there are 2 guests in the hotel. But I have only one room.


*/

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
