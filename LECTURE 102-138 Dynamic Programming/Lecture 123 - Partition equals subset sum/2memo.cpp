#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>&nums , int index , int target,vector<vector<int>> &dp){
        if(target < 0 ) return false;
        if(0 == target) return true;
        if(index>=nums.size()) return false;

        if(dp[index][target]!=-1) return dp[index][target];
        int include = solve(nums , index+1 , target - nums[index],dp);
        int exclude = solve(nums , index+1 , target,dp);
        return dp[index][target] =include | exclude;
    }

    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto&i:nums) sum+=i;
        if(sum%2) return false; //can't divide odd no by 2
        int target = sum/2;
        // now problem becomes target sum , we just have to see if we can make sum/2 target
        vector<vector<int>> dp(nums.size() , vector<int>(target+1 , -1));
        return solve(nums, 0, target,dp);
    }
};