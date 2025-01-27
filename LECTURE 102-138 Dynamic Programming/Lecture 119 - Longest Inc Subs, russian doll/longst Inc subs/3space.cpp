#include<bits/stdc++.h>
using namespace std;
class Solution {
    int LIS (vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int>current(n+1, 0);
        vector<int>next(n+1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) 
                    include = 1 + next[curr + 1];  // Fixed to prev+1

                int exclude = next[prev + 1];
                current[prev + 1] = max(include, exclude);
            }
            next = current;
        }
        return current[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        // so that we can use last element as height
        for(auto&vec:cuboids){
            sort(vec.begin() ,vec.end());
        }
        // sort based on w and l
        sort(cuboids.begin(), cuboids.end());

        // LIS

    }
}; 