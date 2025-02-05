#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    
    // only p will contain * and ?
    bool solve(string &s, string &p, int i , int j ,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return true;
        if(i>0 && j==0) return false;

        if(i==0 && j>0){
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = solve(s,p,i-1,j-1,dp);
        else if(p[j-1] == '*'){
            // consder * as empty string once and charector at other
            dp[i][j] =  (solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp));
        }
        else dp[i][j] =  false;

        return dp[i][j];
    }
public:
    bool isMatch(string &s, string &p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<int>>dp(m ,vector<int>(n,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};