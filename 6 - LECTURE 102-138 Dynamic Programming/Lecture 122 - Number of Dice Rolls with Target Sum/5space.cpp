#include<bits/stdc++.h>
using namespace std;


class Solution {
    int mod = 1000000007;
    int tab (int d  , int faces , int t){
        int n = d;
        vector<vector<int>> dp(n+1 , vector<int>(t+1 ,0));
        vector<int> prev(t+1,0);
        vector<int> curr(t+1,0);

        prev[0] = 1;

        for(int dice = 1; dice <=d ; dice++){
            for(int target = 1; target <=t; target++){
                int ans = 0;
                for(int i = 1 ;i <= faces ;i++){
                    if (target - i >= 0)
                         ans= (ans + prev[target-i]) % mod;
                }

                curr[target] = ans;
            }
            prev = curr;
        }

        return prev[t];

    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return tab(n , k, target);
    }
};