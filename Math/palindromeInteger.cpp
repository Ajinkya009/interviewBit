/* Problem statement: Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Input : 12121
Output : True

Input : 123
Output : False

*/

int Solution::isPalindrome(int A) {
    int n = 1;
    if(A>0 && A<10){
        return 1;
    }
    if(A<0){
        return 0;
    }
    while(A/n>=10){
        n*=10;
    }
    while(A!=0){
        int f = A/n;
        int l = A%10;
        if(f!=l){
            return 0;
        }
        A = (A%n)/10;
        n = n/100;
    }
    return 1;
}