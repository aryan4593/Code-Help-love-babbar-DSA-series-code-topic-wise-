#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&nums , int target){
        if(target == 0) return 1;
        if(target < 0) return 0;

        int ans = 0;
        for(int i= 0 ;i <nums.size() ;i++){
            ans+=solve(nums ,target -nums[i]);
        }
        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums ,target);
    }
};
int main(){}