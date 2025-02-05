#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int index , int op, int k, vector<int>&prices, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;
        if(op == 2*k) return 0;

        if(dp[index][op] != -1) return dp[index][op];

        // if even op no., means buy
        int profit = 0;
        if(op % 2 == 0){
            int buy = solve(index+1, op+1 , k , prices, dp) - prices[index];
            int ignore = solve(index+1, op , k , prices, dp);

            profit = max(buy  , ignore);
        }
        else{
            // means selll
            int sell = solve(index+1 , op + 1 , k ,  prices, dp) + prices[index];
            int ignore = solve(index+1 , op , k , prices, dp);
            profit = max(sell  , ignore);
        }

        return dp[index][op] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int totalOperation = k*2; // for every k, 2 operations i.e buy and sell
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(totalOperation+1, -1));
        return solve(0 , 0 ,k , prices, dp);
    }
};