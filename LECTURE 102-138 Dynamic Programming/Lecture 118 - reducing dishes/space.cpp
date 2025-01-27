#include<bits/stdc++.h>
using namespace std;
class Solution {
    int tab(vector<int>&satis){
        int n = satis.size();
        vector<vector<int>> dp(n+1,  vector<int>(n+1 , 0));
        vector<int> curr (n+1);
        vector<int> next(n+1);
        for(int index = n-1; index>=0; index--){
            for(int time = index; time>=0 ; time--){

                int include = (time+1)*satis[index] + next[time+1];
                
                // exclude
                int exclude = next[time];

                curr[time] = max(include,exclude);
            }
            next = curr;
        }

        return dp[0][0];

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        return tab(satisfaction);
    }
};