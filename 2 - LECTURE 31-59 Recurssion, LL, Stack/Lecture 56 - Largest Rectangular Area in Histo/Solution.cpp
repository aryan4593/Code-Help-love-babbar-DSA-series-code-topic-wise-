#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {


public:


vector<int> nextSmallerElement(vector<int> prices) {
    vector<int> ans(prices.size());
    stack<int> s;
    s.push(-1);

    int i = prices.size() - 1;

    while (i >= 0){
        int curr = prices[i];
        while (s.top()!=-1 && prices[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);

        i--;
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    for (int i =0;i<n;i++){
        while(s.top()!=-1&&arr[s.top()] >= arr[i]){
            s.pop();
        }
    
        ans[i]=s.top();
        s.push(i);

    }
    return ans;
}


int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights);
        vector<int> prev(n);
        prev = prevSmallerElement(heights);
int area= -1;
        for(int i=0;i<n;i++){
            int l = heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b = next[i]-prev[i]-1;

            int newArea = l*b; 

            area=max(area,newArea);
        }

return area;
    }
};