/* Problem Statement: Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Input : [4, 0, 2, 1, 3]
Return : [3, 4, 2, 0, 1]

*/

void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<A.size();i++){
        A[i]+= (A[A[i]]%n)*n;
    }
    for(int i=0;i<A.size();i++){
        A[i]/=n;
    }
}
