/*Problem: Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. */

bool isPrime(int n){
    
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> b;
    
    for(int i=2;i<=A/2;i++){
        int x = A-i;
        
        if(isPrime(i) && isPrime(x)){
            
            if(b.size()==0){
                b.push_back(i);
                b.push_back(x);
            }
            else if(b[0]<=i && b[1]<x){
                b[0] = i;
                b[1] = x;
            }
        }
    }
    return b;
}