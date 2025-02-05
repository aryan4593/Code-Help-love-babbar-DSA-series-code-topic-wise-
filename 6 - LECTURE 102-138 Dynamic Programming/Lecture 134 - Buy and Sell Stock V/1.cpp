// Best Time to Buy and Sell Stock with Transaction Fee

// same as buy and sell stock 2
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    int solve(vector<int>&prices , int index, int canBuy , int fee, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;

        if(dp[index][canBuy] != -1) return dp[index][canBuy] ;
        int profit = 0;
        // buy
        if(canBuy){
            int buy = solve(prices , index+1, 0 , fee, dp) - prices[index];
            int ignore = solve(prices , index+1, 1 , fee, dp) ;
            profit = max(buy , ignore);
        }
        else{
            int sell = solve(prices, index+1 ,1 , fee, dp) + prices[index] - fee;
            int ignore = solve(prices, index+1 , 0 ,fee, dp);
            profit = max(sell , ignore);
        }

        return dp[index][canBuy]  = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2, -1));
        return solve(prices ,0 ,1, fee, dp);
    }
};
int main(){

}