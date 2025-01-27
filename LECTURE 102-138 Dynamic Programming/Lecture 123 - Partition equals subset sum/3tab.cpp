#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool tab(vector<int> &nums, int t) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int index = n - 1; index >= 0; index--) {
            for (int target = 0; target <= t; target++) {
                int include = 0;
                if (target - nums[index] >= 0) {
                    include = dp[index + 1][target - nums[index]];
                }
                int exclude = dp[index + 1][target];

                dp[index][target] = include | exclude;
            }
        }

        return dp[0][t];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;  // If the sum is odd cna't divide it by 2
        
        int target = sum / 2;
        return tab(nums, target);
    }
};
