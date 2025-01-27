#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>&obs, int currLane , int pos,vector<vector<int>> &dp){
        if(pos == obs.size() -1) {
            return 0;
        }
        if(dp[pos][currLane]!=-1) return dp[pos][currLane];

        if(obs[pos+1] != currLane){
            return solve(obs , currLane , pos+1,dp);
        }
        else{
            int ans = INT_MAX;
            for(int i =1 ; i<=3 ;i++){

                if(i != currLane && obs[pos] != i )
                    ans = min(ans , 1 + solve(obs , i, pos,dp));
            }
            return dp[pos][currLane]=ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n+1 ,vector<int>(4, -1));
        return solve(obstacles , 2 , 0, dp);
    }
};
int main(){
    
}