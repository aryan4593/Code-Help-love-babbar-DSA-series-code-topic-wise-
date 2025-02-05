#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

    int solve(int index, vector<int>&prices , int limit , int canBuy,vector<vector<vector<int>>> &dp){
        if(index == prices.size()) return 0;
        if(limit <= 0) return 0;
        if(dp[index][canBuy][limit] != -1) return dp[index][canBuy][limit];
        // buy
        int profit = 0;
        if(canBuy){
            int buy = solve(index+1 , prices , limit , !canBuy,dp) - prices[index];

            int ignore = solve(index+1 , prices , limit , canBuy,dp);

            profit = max(buy  , ignore);

        }
        else{
            int sell = solve(index+1 , prices , limit-1 , !canBuy,dp) + prices[index]; 

            int ignore = solve(index+1 , prices , limit , canBuy,dp);

            profit = max(sell  , ignore);
        }

        return  dp[index][canBuy][limit] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return solve(0 , prices ,2, true, dp);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}