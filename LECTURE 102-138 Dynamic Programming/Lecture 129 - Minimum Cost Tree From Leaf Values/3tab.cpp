#include<bits/stdc++.h>
using namespace std;

class Solution {
    int tab(vector<int>&arr , map<pair<int,int>, int>&maxi){
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int left = n-1; left>=0; left--){
            for(int right = left+1; right<=n ; right++){
                int ans = INT_MAX;
                for(int i=left; i<right; i++){
                    int temp = maxi[{left,i}] * maxi[{i+1 , right}] +
                            dp[left][i] +dp[i+1][right];
                    ans = min(ans,temp);
                }
               dp[left][right] = ans;
            }
        }

        return dp[0][n-1];

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
        return tab(arr, maxi);
    }
};
int main() {
    Solution solution;
    vector<int> arr = {6, 2, 4}; // Example input
    cout << "Minimum Cost Tree From Leaf Values: " << solution.mctFromLeafValues(arr) << endl;
    return 0;
}