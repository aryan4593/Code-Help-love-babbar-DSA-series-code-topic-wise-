#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solve(vector<int>&nums , int target){
        vector<__int128>dp(target+1 , 0);
        dp[0] = 1;

        for(int i = 1  ;i <target+1 ;i++){
            for(int j = 0; j < nums.size() ;j++){
                if(i -nums[j] >=0 )
                    dp[i]+=dp[i -nums[j]];
            }
        }

        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int>dp(target+1 , -1);
        return solve(nums ,target);
    }
};

int main(){}