#include<bits/stdc++.h>
using namespace std;
class Solution
{
    int solve(int n , int x , int y , int z,vector<int>&dp){
        if(n ==0 ) return 0;
        if(n < 0) return INT_MIN;
        
        if(dp[n] != -1 ) return dp[n];
        
        int ansX = 1 + solve(n-x ,x,y,z ,dp);
        int ansY = 1 + solve(n-y , x ,y ,z,dp);
        int ansZ = 1 + solve(n-z , x,y,z,dp);
        
        dp[n] = max(ansX , max(ansY, ansZ));
        
        return dp[n];

    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1 ,-1);
        int ans = solve(n , x , y , z ,dp);
        return (ans < 0) ? 0 : ans;
    }
};