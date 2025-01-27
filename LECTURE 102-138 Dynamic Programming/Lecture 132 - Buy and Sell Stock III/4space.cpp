#include<bits/stdc++.h>
using namespace std;
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

int tab(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
       vector<vector<int>>curr (2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3,0)) ;

        for (int index = n - 1; index >= 0; index--) {
            for (int limit = 1; limit <= 2; limit++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int profit = 0;
                    if (canBuy) {

                        int buy = next[0][limit] - prices[index];
                        int ignore = next[1][limit];
                        profit = max(buy, ignore);
                    } else {
                    
                        int sell = next[1][limit - 1] + prices[index];
                        int ignore = next[0][limit];
                        profit = max(sell, ignore);
                    }
                   curr[canBuy][limit] = profit;
                }
            }
            next = curr;
        }

        return curr[1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        return tab(prices);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}

int main(){

}

