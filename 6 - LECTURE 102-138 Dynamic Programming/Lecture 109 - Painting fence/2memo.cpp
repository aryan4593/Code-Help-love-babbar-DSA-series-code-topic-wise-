#include<bits/stdc++.h>
using namespace std;

class Solution {
    // last 2 will be different or they will be same
    int solve(int n , int k ,vector<int>&dp){
        if(n==1) return k;
        if(n==2) return k + (k*(k-1));  //k**2
        if(dp[n] != -1) return dp[n];
        //  diiferent + same
        dp[n] = (solve(n-2 , k ,dp) * (k-1)) + (solve(n-1 ,k,dp) * (k-1));
        return dp[n];
    }
  public:
    int countWays(int n, int k) {
        // code here
        vector<int>dp(n+1 ,-1);
        return solve(n, k ,dp);
    }
};

int main(){
    
}