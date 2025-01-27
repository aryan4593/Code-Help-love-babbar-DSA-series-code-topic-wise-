#include<bits/stdc++.h>
using namespace std;
class Solution {

    
    int solve(int n){
        vector<int>dp(n+1,0);
        dp[1] = 0;
        dp[2] =1;
        
        for(int i = 3; i <=n ; i++){
            dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
  public:
    int countDer(int n) {

        int ans = solve(n );
        return ans;
    }
};
int main(){
    
}