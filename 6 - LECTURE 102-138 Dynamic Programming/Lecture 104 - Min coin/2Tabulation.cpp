#include<bits/stdc++.h>
using namespace std;

class Solution {
    int tabulation(vector<int>&coins , int x){
        vector<int>dp(x+1 , INT_MAX); 

        dp[0] = 0;

        for(int i = 1 ; i < x +1 ; i++){
            ///solving for every amount 

            for(int j = 0 ; j < coins.size() ; j++){
                int coinAmt = coins[j];

                if(i - coinAmt >= 0 && dp[i-coinAmt] != INT_MAX) //check for vaid index
                    dp[i] = min (dp[i] , 1 + dp[i - coinAmt]);
            }
        }

        return dp[x] == INT_MAX ? -1 : dp[x];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        return tabulation(coins , amount);
    }
};
int main(){
    return 0;;
}