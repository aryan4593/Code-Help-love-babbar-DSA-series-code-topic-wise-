#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums ,int curr , int prev){
        if(curr == nums.size()) return 0;

        // include
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) 
            include = 1 + solve(nums , curr+1 , curr);

        // exclude
            int exclude = solve(nums,  curr+1 , prev);

        return max(include , exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums ,  0 ,-1);
    }
};

