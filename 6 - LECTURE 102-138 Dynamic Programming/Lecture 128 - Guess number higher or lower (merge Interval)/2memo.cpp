#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int st, int end, vector<vector<int>> &dp){
        if(st >= end) return 0;
        if(dp[st][end] != -1) return dp[st][end];
        int ans = INT_MAX;

        for(int i =  st ; i <= end ; i++){
            int lower = solve(st,i-1, dp);
            int higher = solve(i+1, end, dp);
            // we assume that answer is wrong
            int tempAns = i + max (lower , higher);
            ans = min(ans, tempAns);
        }
        return dp[st][end] = ans;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1,n,dp);
    }
};
int main() {
    // Your code here

    return 0;
}