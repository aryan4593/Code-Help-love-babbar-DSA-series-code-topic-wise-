#include<bits/stdc++.h>
using namespace std;

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

    int tab(vector<int>&prices, int k){
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2*k+2, 0));

        vector<int> next (2*k +2 ,0);
        vector<int> curr (2*k +2 ,0);

        for(int index = n-1; index>=0; index--){
            for(int op = 2*k; op >= 0; op--){
                int profit = 0;
                if(op % 2 == 0){
                    int buy = next[op+1] - prices[index];
                    int ignore =  next[op] ;

                    profit = max(buy  , ignore);
                }
                else{
                    // means selll
                    int sell = next [op+1] + prices[index];
                    int ignore = next [op];
                    profit = max(sell  , ignore);
                }

               curr[op] = profit;
            }
            next = curr;
        }

        return curr[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return tab(prices , k);
    }
};