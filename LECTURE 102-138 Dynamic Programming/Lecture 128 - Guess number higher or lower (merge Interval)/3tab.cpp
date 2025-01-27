#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Solution {

    int tab(int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int st = n ; st >= 1; st--){
            for(int end = st; end<=n; end++){
                
                if(st == end) continue;

                else{
                    int ans = INT_MAX;
                    for(int i =  st ; i <= end ; i++){
                        int lower = dp[st][i-1];
                        int higher = (i + 1 <= n) ? dp[i+1][end] : 0; 
                        // we assume that answer is wrong
                        int tempAns = i + max (lower , higher);
                        ans = min(ans, tempAns);
                    }
                     dp[st][end] = ans;
                }
            }
        }

        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        return tab(n);
    }
};