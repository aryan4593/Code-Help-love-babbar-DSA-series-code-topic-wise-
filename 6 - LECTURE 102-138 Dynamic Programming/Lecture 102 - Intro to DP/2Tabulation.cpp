#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int nthFibonacci(int n) {
        
        if(n==0 or n==1) return n;
        
        vector<int> dp (n+1 );
        
        // base case
        dp[0] =0;
        dp[1] =1;
        
        for(int i = 2 ; i<=n ;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
int main(){
    return 0;
}