// same as prev ques but we need to make sure first index and last index
#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) return 0;

        if (dp[start] != -1) return dp[start];

        // Include 
        int include = nums[start] + solve(nums, start + 2, end, dp);

        // Exclude 
        int exclude = solve(nums, start + 1, end, dp);

        dp[start] = max(include, exclude);
        return dp[start];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        int max1 = solve(nums, 0, n - 2, dp1);

        vector<int> dp2(n, -1);
        int max2 = solve(nums, 1, n - 1, dp2);

        return max(max1, max2);
    }
};


//7 2 3 5 6 7 10 1

// 10 1 1 10 1 1 10 1 1 10


int main(){

    Solution s1;
    vector<int> vec = {1,3,1,3,100};
    s1.rob(vec);
};
