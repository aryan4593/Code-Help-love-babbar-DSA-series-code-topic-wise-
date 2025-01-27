#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// Top down or memoization
class Solution {
    
    int solve(int n , vector<int>&dp){
        if(n ==0 ||n==1) return n;
        
        if(dp[n] != -1) return dp[n];
        
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        
        return dp[n];
    }
  public:
    int nthFibonacci(int n) {
        vector<int>dp(n+1 , -1);
        
        return solve(n , dp);
    }
};
