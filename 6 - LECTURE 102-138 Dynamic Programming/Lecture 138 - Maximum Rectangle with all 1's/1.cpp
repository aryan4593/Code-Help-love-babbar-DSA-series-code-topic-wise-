#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;
class Sol {
    vector<int> nextSmallerElement(vector<int>&arr){
        stack<int> st;
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0; i<arr.size(); i++){
            int num = arr[i];
            while(!st.empty() && arr[st.top()] > num){
                ans[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()){
            ans[st.top()] = n;
            st.pop();
        }
        return ans;
    }

    vector<int>prevSmallerElement(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=n-1; i>=0; i--){
            int num = arr[i];
            while(!st.empty() && arr[st.top()] > num){
                ans[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = prevSmallerElement(heights);

        int maxArea = 0;

        for(int i=0; i<heights.size(); i++){    
            int left =  prev[i];
            int right =  next[i];

            int area = (right - left -1) * heights[i];

            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        vector<int>histogram (n ,0);
        int maxArea = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] =='1') histogram[j]++;
                else{
                    histogram[j] = 0;
                }
            }
            Sol s1;
            int area = s1.largestRectangleArea(histogram);
            maxArea = max (area, maxArea);
        }

        return maxArea;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution sol;
    int maxRectangle = sol.maximalRectangle(matrix);
    cout << "The maximum rectangle area is: " << maxRectangle << endl;

    return 0;
}