#include<bits/stdc++.h>
using namespace std;

  class Solution {

    int tab(vector<int>&obs){
        int n = obs.size()-1 ;
        vector<vector<int>> dp(4, vector<int>(n+1,1e9));

        // base case
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int pos = n-1; pos>=0 ;pos--){
            for(int currLane=1; currLane<= 3;currLane++){
                if(obs[pos+1] != currLane){
                    dp[currLane][pos] =  dp[currLane][pos+1];
                }
                else{
                    int ans = INT_MAX;
                    for(int i =1 ; i<=3 ;i++){

                        if(i != currLane && obs[pos] != i )
                            ans = min(ans , 1 +  dp[i][pos+1]);
                    }
                    dp[currLane][pos]=ans;
                }
            }
        }

        return min(dp[2][0] , 1+ min (dp[1][0] ,dp[3][0]));


    }
public:
    int minSideJumps(vector<int>& obstacles) {
       return tab(obstacles);
    }
};