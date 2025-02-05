#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveMem(vector<int>& coins, int x , vector<int>&dp){
        if(x==0) return 0;
        if(x < 0) return INT_MAX;

        if(dp[x] != -1) return dp[x];

        int mini = INT_MAX;
        for(int i = 0; i < coins.size() ;i++){
            int ans = solveMem (coins , x - coins[i] , dp);

            if(ans != INT_MAX){
                mini = min (mini , 1+ans);
            }
        }
        dp[x] = mini;

        return dp[x];
    }

    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1 , -1);

        int ans = solveMem (coins , amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};


int main(){
    return 0;
}