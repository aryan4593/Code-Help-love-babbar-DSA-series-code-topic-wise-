#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<vector<char>>& matrix ,int i , int j ,int &maxi,vector<vector<int>>&dp){
        if(i >= matrix.size() || j >= matrix[0].size()) 
                return 0; //invalide index;
        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(matrix, i ,j+1, maxi,dp);
        int diag = solve(matrix , i+1 ,j+1, maxi,dp);
        int down = solve(matrix ,i+1 ,j, maxi,dp);

        if(matrix[i][j] == '1'){
            int ans = min (right , min(diag ,down)) + 1;
            maxi = max (maxi ,ans);
            dp[i][j]= ans;
            return ans;
        }
        else{
            dp[i][j]= 0;
            return 0; // can't make square1
        }
    }

 int tab (vector<vector<char>>& matrix ){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(row+1 ,vector<int>(col+1, 0));

        for(int i = row-1;i>=0;i--){
            for(int j = col-1; j>=0 ;j--){
                int right = dp[i][j+1];
                int diag = dp [i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    int ans = min (right , min(diag ,down)) + 1;
                    maxi = max (maxi ,ans);
                    dp[i][j]= ans;
                }
                else{
                    dp[i][j]= 0;
                }
            }
        }

        return maxi*maxi;

    }

    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>>dp(matrix.size() ,vector<int>(matrix[0].size(), -1));

         solve(matrix , 0,0,maxi, dp);
         return maxi * maxi;
    }
};