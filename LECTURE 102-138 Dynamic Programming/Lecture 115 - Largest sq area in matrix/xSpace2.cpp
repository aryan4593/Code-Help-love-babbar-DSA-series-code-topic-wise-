class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        int maxi = 0;
        int prev = 0;  // Tracks the top-left (diagonal) value during iteration

        vector<int> dp(col + 1, 0);  // 1D DP array to simulate in-place calculation

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int temp = dp[j];  // Store the current value (before overwriting)
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    maxi = max(maxi, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;  // Update prev to be the original dp[j]
            }
        }
        return maxi * maxi;
    }
};
