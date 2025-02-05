#include<bits/stdc++.h>
using namespace std;
class Solution
{
    int solveTab(int n , int x , int y , int z){
        vector<int>dp(n+1 , INT_MIN);
        dp[0] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            
            if(i-x >=0)
                dp[i] = max(dp[i] , 1+dp[i-x]);
            if(i-y >=0)
                dp[i] = max(dp[i] , 1+dp[i-y]);
            if(i-z >=0)
                dp[i] = max(dp[i] , 1+dp[i-z]);
        }
        
        return dp[n];
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1 ,-1);
        int ans = solveTab(n , x , y , z );
        return (ans < 0) ? 0 : ans;
    }
};
