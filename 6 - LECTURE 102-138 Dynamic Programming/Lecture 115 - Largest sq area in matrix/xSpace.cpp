#include<bits/stdc++.h>
using namespace std;

class Solution {
    int space (vector<vector<char>>& matrix ){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(row+1 ,vector<int>(col+1, 0));
        vector<int> curr(col+1 ,0);
        vector<int> next (col+1,0);
        for(int i = row-1;i>=0;i--){
            for(int j = col-1; j>=0 ;j--){
                int right = curr[j+1];
                int diag = next[j+1];
                int down = next[j];

                if(matrix[i][j] == '1'){
                    int ans = min (right , min(diag ,down)) + 1;
                    maxi = max (maxi ,ans);
                    curr[j]= ans;
                }
                else{
                    curr[j]= 0;
                }
            }
            next = curr;
        }

        return maxi*maxi;

    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         return space(matrix);
    }
};