#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int index, vector<int>&prices ,bool buy, vector<vector<int>>&dp){
        if(index == prices.size()) return 0;

        int profit = 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            int purchase = solve(index+1 , prices , !buy, dp) - prices[index];

            int ignore = solve(index+1, prices , buy, dp);

            profit = max(purchase , ignore);
        }
        else{
            // we are selling 
            int sell = solve(index+1 , prices, !buy, dp) + prices[index];
            int ignore = solve(index+1 , prices , buy, dp);
            profit  = max(sell , ignore);
        }

        return dp[index][buy] = profit;
    }

    int tab (vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));  

        for(int index = n-1; index>=0 ; index--){
            for(int buy =0; buy<=1; buy++){
                int profit = 0;

                if(buy){
                    int purchase = dp[index+1][!buy] - prices[index];
                    int ignore = dp[index+1][buy];

                    profit = max(purchase , ignore);
                }
                else{
                    // we are selling 
                    int sell = dp[index+1][!buy] + prices[index];
                    int ignore = dp[index+1][buy];
                    profit  = max(sell , ignore);
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tab(prices);
    }
};
int main(){
    
}