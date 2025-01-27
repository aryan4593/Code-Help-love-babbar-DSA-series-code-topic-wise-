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

class Solution1 {
int tab(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--) {
        int ans1 = costs[0] + dp[k + 1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++);
        int ans2 = costs[1] + (i < n ? dp[i] : 0);

        int j;
        for (j = k; j < n && days[j] < days[k] + 30; j++);
        int ans3 = costs[2] + (j < n ? dp[j] : 0);

        dp[k] = min(ans1, min(ans2, ans3));
    }
    return dp[0];
}


public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return tab(days ,costs);
    }
};

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solve(days ,costs ,0,dp);
    }
};

