#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    int solve(int index, vector<int>&prices , int limit , int canBuy){
        if(index == prices.size()) return 0;
        if(limit <= 0) return 0;
        // buy
        int profit = 0;
        if(canBuy){
            int buy = solve(index+1 , prices , limit , !canBuy) - prices[index];

            int ignore = solve(index+1 , prices , limit , canBuy);

            profit = max(buy  , ignore);

        }
        else{
            int sell = solve(index+1 , prices , limit-1 , !canBuy) + prices[index]; 

            int ignore = solve(index+1 , prices , limit , canBuy);

            profit = max(sell  , ignore);
        }

        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        return solve(0 , prices ,2, true);
    }
};
int main() {

    return 0;
}