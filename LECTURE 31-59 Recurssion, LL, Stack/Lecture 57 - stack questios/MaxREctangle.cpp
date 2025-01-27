#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution {
private:
    vector<int> nextSmallerElement(const vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && prices[s.top()] >= prices[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);

        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            int height = heights[i];
            int width = (next[i] == -1 ? n : next[i]) - prev[i] - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix1(n, vector<int>(m, 0));

        // Convert matrix of chars to matrix of ints
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                matrix1[i][j] = (matrix[i][j] == '1') ? 1 : 0;
            }
        }

        int maxArea = largestRectangleArea(matrix1[0]);

        // Compute area for each row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix1[i][j] != 0) {
                    matrix1[i][j] += matrix1[i - 1][j];
                } else {
                    matrix1[i][j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(matrix1[i]));
        }

        return maxArea;
    }
};