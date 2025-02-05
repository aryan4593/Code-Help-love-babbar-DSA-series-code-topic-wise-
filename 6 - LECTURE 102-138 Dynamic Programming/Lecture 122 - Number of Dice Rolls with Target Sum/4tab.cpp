#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int dice , int faces , int target,vector<vector<int>> &dp){
        if(target<0) return 0;
        if(target != 0 && dice == 0) return 0;
        if(target == 0 && dice!=0) return 0;
        if(target == 0 && dice == 0) return 1; 

        if(dp[dice][target]!=-1) return dp[dice][target];
        int ans = 0;
        for(int i = 1 ;i <= faces ;i++){
            ans+= solve(dice-1, faces ,target-i,dp);//as we are using 1 dice and decrementing target by i
        }

        return dp[dice][target] = ans;
    }
    int mod = 1000000007;


    int mod = 1000000007;
    int tab (int d  , int faces , int t){
        int n = d;
        vector<vector<int>> dp(n+1 , vector<int>(t+1 ,0));

        dp[0][0] = 1;

        for(int dice = 1; dice <=d ; dice++){
            for(int target = 1; target <=t; target++){
                int ans = 0;
                for(int i = 1 ;i <= faces ;i++){
                    if (target - i >= 0)
                         ans= (ans + dp[dice-1][target-i]) % mod;
                }

                dp[dice][target] = ans;
            }
        }

        return dp[d][t];

    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return tab(n , k, target);
    }
};