#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>&satis ,int index , int time,vector<vector<int>> &dp){
        if(index == satis.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];
        // include 
        int include = (time+1)*satis[index] +  solve(satis ,index+1 , time+1,dp);
        
        // exclude
        int exclude = solve(satis , index+1 ,time,dp);

        return dp[index][time] = max(include , exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n,  vector<int>(n+1 , -1));
        return solve(satisfaction ,0 , 0,dp);
    }
};
int main(){
    
}