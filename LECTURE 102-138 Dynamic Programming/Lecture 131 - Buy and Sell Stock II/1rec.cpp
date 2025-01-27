#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int solve(int index, vector<int>&prices ,bool buy){
        if(index == prices.size()) return 0;

        int profit = 0;
        if(buy){
            int purchase = solve(index+1 , prices , !buy) - prices[index];

            int ignore = solve(index+1, prices , buy);

            profit = max(purchase , ignore);
        }
        else{
            // we are selling 
            int sell = solve(index+1 , prices, !buy) + prices[index];
            int ignore = solve(index+1 , prices , buy);
            profit  = max(sell , ignore);
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        return solve(0, prices , true);
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
}