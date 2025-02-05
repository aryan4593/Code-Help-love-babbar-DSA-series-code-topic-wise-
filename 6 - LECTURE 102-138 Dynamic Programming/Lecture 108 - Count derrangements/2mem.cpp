
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n , vector<int>&dp){
        if(n==1) return 0;
        if(n==2) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = (n-1) * (countDer(n-1) + countDer(n-2));
        dp[n] = ans;
        
        return dp[n];
    }
  public:
    int countDer(int n) {
        vector<int>dp(n+1 , -1);
        int ans = solve(n , dp);
        return ans;
    }
};
int main(){
    
}