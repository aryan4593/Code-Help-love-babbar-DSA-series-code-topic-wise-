#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& slices, int index, int end, int n, vector<vector<int>>& dp) {
        if (n == 0 || index > end) return 0;
        if (dp[index][n] != -1) return dp[index][n];
        
        int take = slices[index] + solve(slices, index + 2, end, n - 1, dp);
        int notTake = solve(slices, index + 1, end, n, dp);
        
        return dp[index][n] = max(take, notTake);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int n = k / 3;
        
        vector<vector<int>> dp1(k, vector<int>(n + 1, -1));
        // Case 1: Include first slice, exclude last
        int case1 = solve(slices, 0, k - 2, n, dp1);
        
        vector<vector<int>> dp2(k, vector<int>(n + 1, -1));
        // Case 2: Exclude first slice, include last
        int case2 = solve(slices, 1, k - 1, n, dp2);
        
        return max(case1, case2);
    }
};
int main(){
    
}