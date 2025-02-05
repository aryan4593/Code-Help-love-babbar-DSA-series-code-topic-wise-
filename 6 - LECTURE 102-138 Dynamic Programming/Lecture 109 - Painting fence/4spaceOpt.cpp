#include<bits/stdc++.h>
using namespace std;


class Solution {
    // last 2 will be different or they will be same
int solve(int n , int k){
    if(n==1) return k;
    // vector<int>dp(n+1, 0);
    int prev1 = k;
    int prev2 = k + (k*(k-1));

    for(int i=3 ; i <=n ; i++){
        int curr = (prev1 * (k-1)) + (prev2 * (k-1));

        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
  public:
    int countWays(int n, int k) {
        // code here
        return solve(n, k);
    }
};


int main(){
    
}