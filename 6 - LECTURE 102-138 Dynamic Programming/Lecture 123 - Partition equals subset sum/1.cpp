#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>&nums , int index , int sum , int target){
        if(sum == target) return true;
        if(index>=nums.size()) return false;
        if(target < sum ) return false;

        int include = solve(nums , index+1 , sum+nums[index] , target);
        int exclude = solve(nums , index+1 , sum, target);
        return include | exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto&i:nums) sum+=i;
        if(sum%2) return false; //can't divide odd no by 2

        // now problem becomes target sum , we just have to see if we can make sum/2 target

        return solve(nums, 0,0, sum/2);
    }
};