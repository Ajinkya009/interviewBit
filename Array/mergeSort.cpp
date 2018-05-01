#include <iostream>
#include <vector>
using namespace std;

void conquer(vector<int> &arr, int min, int center, int max){
    int i=0,j=0,k=min;
    vector<int> left(arr.begin()+min,arr.begin()+center+1);
    vector<int> right(arr.begin()+center+1,arr.begin()+max+1);
    /*cout<<"left"<<"\n";
    for(int i=0;i<left.size();i++){
            cout<< left[i] << '\n';
    }
    cout<<"right"<<"\n";
    for(int i=0;i<right.size();i++){
            cout<< right[i] << '\n';
    }*/
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else if(left[i]>right[j]){
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<left.size()){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<right.size()){
        arr[k] = right[j];
        j++;
        k++;
    }
    

}

void divide(vector <int> &arr, int min, int max) {
    if(min<max){
        int center = min+(max-min)/2;
        /*cout<< "min" << min << '\n';
        cout<< "center" << center << '\n';
        cout<< "max" << max <<'\n';
        cout<< "first array" <<'\n';*/
        divide(arr,min,center);
        divide(arr,center+1,max);
        conquer(arr,min,center,max);
        cout<<"merge output"<<"\n";
        for(int n=0;n<arr.size();n++){
                cout<< arr[n] << '\n';
        }
    }
    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    divide(arr,0,n-1);
    return 0;
}


