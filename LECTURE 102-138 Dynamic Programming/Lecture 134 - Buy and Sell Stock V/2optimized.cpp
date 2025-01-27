#include<bits/stdc++.h>
using namespace std;


class Solution {
    int FEE;
    int tab (vector<int>& prices){
        int n = prices.size();
        vector<int>next(2,0);
        vector<int>curr(2,0);

        for(int index = n-1; index>=0 ; index--){
            for(int buy =0; buy<=1; buy++){
                int profit = 0;

                if(buy){
                    int purchase = next[!buy] - prices[index];
                    int ignore = next[buy];

                    profit = max(purchase , ignore);
                }
                else{
                    // we are selling 
                    int sell = next[!buy] + prices[index] - FEE;
                    int ignore = next[buy];
                    profit  = max(sell , ignore);
                }

                curr[buy] = profit;

            }
            next = curr;
        }
        return curr[1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        this->FEE = fee;

        return tab(prices);
    }
};