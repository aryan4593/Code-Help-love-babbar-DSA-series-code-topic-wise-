#include<bits/stdc++.h>
using namespace std;


class Solution {
    // last 2 will be different or they will be same
    int solve(int n , int k){
        if(n==1) return k;
        if(n==2) return k + (k*(k-1));  //k**2
        //  diiferent + same
        int ans = (solve(n-2 , k) * (k-1)) + (solve(n-1 ,k ) * (k-1));
        return ans;
    }
  public:
    int countWays(int n, int k) {
        // code here
        return solve(n, k);
    }
};

int solve1(int n , int k){
    if(n==1) return k;
    vector<int>dp(n+1, 0);
    dp[1] = k;
    dp[2] = k + (k*(k-1));

    for(int i=3 ; i <=n ; i++){
        dp[i] = (dp[i-2] * (k-1)) + (dp[i-1] * (k-1));
    }
    return dp[n];
}
int main(){
    
}