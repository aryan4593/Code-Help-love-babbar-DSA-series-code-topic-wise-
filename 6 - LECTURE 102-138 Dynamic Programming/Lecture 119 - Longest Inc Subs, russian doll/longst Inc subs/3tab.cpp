#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int tab (vector<int> nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) 
                    include = 1 + dp[curr + 1][curr + 1];  // Fixed to prev+1

                int exclude = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return tab(nums);
    }
};

//  prev -1  -> n-1   so n element