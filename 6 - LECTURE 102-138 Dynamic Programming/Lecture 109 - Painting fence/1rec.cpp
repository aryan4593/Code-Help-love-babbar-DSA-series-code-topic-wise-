#include<bits/stdc++.h>
using namespace std;

class Solution {
    // last 2 will be different or they will be same
    int solve(int n , int k){
        if(n==1) return k;
        if(n==2) return k + (k*(k-1));  //k**2
        //  diiferent + same
        int ans = (solve(n-2 , k) * (k-1)) + (solve(n-1 ,k ) * (k-1));
        return ans;
    }
  public:
    int countWays(int n, int k) {
        // code here
        return solve(n, k);
    }
};
