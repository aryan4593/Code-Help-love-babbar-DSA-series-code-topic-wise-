#include <iostream>
#include <vector>

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
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  

        return solve(0, prices , true, dp);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}