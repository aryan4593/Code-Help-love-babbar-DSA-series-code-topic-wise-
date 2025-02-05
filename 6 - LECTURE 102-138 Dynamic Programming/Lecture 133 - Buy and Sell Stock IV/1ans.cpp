// same as last question

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int tab(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
       vector<vector<int>>curr (2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1,0)) ;

        for (int index = n - 1; index >= 0; index--) {
            for (int limit = 1; limit <= k; limit++) {
                for (int canBuy = 0; canBuy <= 1; canBuy++) {
                    int profit = 0;
                    if (canBuy) {

                        int buy = next[0][limit] - prices[index];
                        int ignore = next[1][limit];
                        profit = max(buy, ignore);
                    }
                    else {

                        int sell = next[1][limit - 1] + prices[index];
                        int ignore = next[0][limit];
                        profit = max(sell, ignore);
                    }
                   curr[canBuy][limit] = profit;
                }
            }
            next = curr;
        }

        return curr[1][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        return tab(prices , k);
    }
};

