#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n ,vector<int>&dp){
        if(n==0) return 0; //constrain
        // if(n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = n;
        for(int i = 1; i<= sqrt(n) ;i++){
            int iAns = 1 + solve(n-i*i ,dp) ;
            ans = min (ans , iAns);
        }
        dp[n]= ans;
        return dp[n];
    }
    int tab(int n){
        vector<int>dp(n+1 ,n);
        dp[0]=0;

        for(int i = 1; i < n+1 ;i++){
            for(int j =1; j <= sqrt(i) ;j++){
                if(i - j*j >=0)
                dp[i] = min(dp[i] ,1 + dp[i - j*j]);
            }
        }
        for(auto i:dp) cout<<i<<" ";
        return dp[n];
    }
public:
    int numSquares(int n) {
        return tab(n);
        vector<int>dp(n+1 ,-1);
        return solve(n ,dp);
    }
};

// loop thro numbers from 1 to sqrt(n), check each combination min is the answer

// loop thro numbers from 1 to sqrt(n), check each combination min is the answer
int main(){}