#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&arr , map<pair<int,int>, int>&maxi , int left , int right, vector<vector<int>> &dp){
        if(left == right) return 0; //leaf node
        
        int ans = INT_MAX;
        if(dp[left][right]!= -1) return dp[left] [right];
        for(int i=left; i<right; i++){
            int temp = maxi[{left,i}] * maxi[{i+1 , right}] +
                     solve(arr, maxi ,left,i,dp) + solve(arr,maxi ,i+1, right,dp);
            ans = min(ans,temp);
        }
        return dp[left][right] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>,int> maxi;
        for(int i=0 ;i<n ;i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j< n ;j++){
                 maxi[{i,j}]= max(arr[j] ,  maxi[{i,j-1}]);
            }
        }
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(arr , maxi,0,n-1,dp);
    }
};
int main() {
    Solution solution;
    vector<int> arr = {6, 2, 4}; // Example input
    cout << "Minimum Cost Tree From Leaf Values: " << solution.mctFromLeafValues(arr) << endl;
    return 0;
}