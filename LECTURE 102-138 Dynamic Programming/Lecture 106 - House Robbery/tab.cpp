#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveTab(vector<int>& nums, int start, int end) {
        if (start > end) return 0;

        int size = end - start + 1;
        vector<int> dp(size, 0);

        dp[0] = nums[start];
        if (size > 1)
            dp[1] = max(nums[start + 1], dp[0]);

        for (int i = 2; i < size; i++) {
            int include = dp[i - 2] + nums[start + i];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }

        return dp[size - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        //  Exclude the last house
        int max1 = solveTab(nums, 0, n - 2);

        //  Exclude the first house
        int max2 = solveTab(nums, 1, n - 1);

        return max(max1, max2);
    }
};