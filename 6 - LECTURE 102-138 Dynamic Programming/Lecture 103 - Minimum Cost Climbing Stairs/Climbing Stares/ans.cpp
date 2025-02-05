#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n , int curr,unordered_map<int ,int>&dp){
        if(curr == n) return 1;
        if(curr>n) return 0;

        if(dp.find(curr+1) ==dp.end()) dp[curr+1] = solve(n , curr+1 , dp);
        if(dp.find(curr+2) == dp.end()) dp[curr+2] = solve(n , curr+2 ,dp);

        return dp[curr+1] + dp[curr+2];
    }
public:
    int climbStairs(int n) {
        int curr = 0;
        unordered_map<int ,int>dp;
        return solve(n , curr ,dp);
    }
};