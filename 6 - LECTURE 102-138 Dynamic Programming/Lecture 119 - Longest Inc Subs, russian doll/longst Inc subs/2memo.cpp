#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums ,int curr , int prev,vector<vector<int>> &dp){
        if(curr == nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];  //-1 to handel -1
        // include
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) 
            include = 1 + solve(nums , curr+1 , curr,dp);

        // exclude
            int exclude = solve(nums,  curr+1 , prev,dp);

        return dp[curr][prev+1] = max(include , exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n+1,vector<int>(n+1 ,-1) );
        return solve(nums ,  0 ,-1,dp);
    }
};

//  prev -1  -> n-1   so n element