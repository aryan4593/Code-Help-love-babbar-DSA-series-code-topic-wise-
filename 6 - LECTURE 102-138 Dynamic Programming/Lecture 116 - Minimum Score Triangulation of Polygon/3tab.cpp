#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& values ,int i ,int j ,vector<vector<int>>&dp){
        if(i+1 == j){
            //means we have only 2 nodes
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1 ; k < j ;k++){
            int temp = values[i]*values[j]*values[k] + solve(values ,i , k ,dp) + solve(values ,k , j,dp);
            ans = min(ans ,  temp);
        }

        return dp[i][j] =  ans;
    }

    int tab(vector<int, int>values){
        int n = values.size();
        vector<vector<int>>dp (n , vector<int>(n ,0));

        for(int i = n-1; i>=0;i--){
            for(int j = i+2 ; j<n ;j++){
                int ans = INT_MAX;
                for(int k = i+1 ; k < j ;k++){
                    int temp = values[i]*values[j]*values[k] + dp[i][k]+ dp[k][j];
                    ans = min(ans ,  temp);
                }

                 dp[i][j] =  ans;
            }
        }

        return dp[0][n-1];


    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp (n+1 , vector<int>(n+1 ,-1));
        return solve(values ,0 , n-1,dp);
    }
};