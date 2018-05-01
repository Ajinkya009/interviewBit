#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void maxset(vector<int> &A) {
    int res = 0;
    int sum = 0;
    int c = 0;
    vector< pair<int,int> > b(1,make_pair(0,0));

    for(int i=0; i<A.size();i++){

        while(i<A.size()&&A[i]>=0){

             c++;
             sum+=A[i];
             i++;

        }

         if(res<sum){
             res = sum;
             b[0] = make_pair(i-c,c);
         }
         else if(res==sum && (c>b[0].second || i-c<b[0].first)){
             //cout<<"here"<<'\n';
             b[0] = make_pair(i-c,c);
             //cout<< b[0].first << '\t' << b[0].second <<'\n';
         }
        c = 0;
        sum = 0;
    }
    cout<< b[0].first << '\t' << b[0].second <<'\n';
     vector<int> output;
     for(int i=b[0].first;i<b[0].first+b[0].second;i++){
         output.push_back(A[i]);
         cout<< A[i] << '\n';
     }

}

int main(){
    vector<int> a = {0,0,-1,0};
    maxset(a);
    return 0;
}
