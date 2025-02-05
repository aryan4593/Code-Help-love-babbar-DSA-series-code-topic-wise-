#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& days, vector<int>& costs ,int index,vector<int>&dp){
        if(index >= days.size()){
            return 0;
        }

        if(dp [index] != -1) return dp[index];
        // 1-day
        int ans1 =costs[0] + solve(days ,costs ,index+1,dp);

        // 7-days
        int i;
        for( i = index; i < days.size() && days[i] < days[index] + 7 ;i++);
        int ans2 = costs[1]+ solve(days ,costs ,i,dp);

        // 30-days
        int j;
        for(j = index ; j < days.size() && days[j] < days[index]+30 ;j++);
        int ans3 = costs[2]+ solve(days ,costs, j,dp);

        dp[index] =  min(ans1, min(ans2,ans3));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size() +1 ,-1);
        return solve(days ,costs ,0,dp);
    }
};

