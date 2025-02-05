#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int> &nums , int i, vector<int>&dp){
    if(i >= nums.size()){
        return 0;
    }

    if(dp[i] != -1) return dp[i];


    // include
    int include = nums[i] + solve(nums, i+2, dp);

    // exclude 
    int exclude = solve(nums,  i+1 , dp);

    dp[i] = max(include , exclude);
    return dp[i];
}

int solveByTab (vector<int>&nums ){
    vector<int>dp(nums.size() , 0);

    dp[0] = nums[0];
    dp[1] = max(dp[0] , dp[1]);

    for(int i = 2 ; i < nums.size() ; i++){
        
        int include = nums[i] + dp[i-2];
        int exclude = nums[i-1];

        dp[i] = max(include , exclude);
    }

    return dp[nums.size() -1];
}

int maximumNonAdjacentSum(vector<int> &nums){

    int index = 0;
    vector<int> dp (nums.size() , -1);

    return solve(nums,index, dp);
}

int solve(vector<int> &nums , int i, vector<int>&dp){
    if(i >= nums.size()){
        return 0;
    }

    if(dp[i] != -1) return dp[i];


    // include
    int include = nums[i] + solve(nums, i+2, dp);

    // exclude 
    int exclude = solve(nums,  i+1 , dp);

    dp[i] = max(include , exclude);
    return dp[i];
}

int solveByTab (vector<int>&nums ){
    vector<int>dp(nums.size() , 0);

    dp[0] = nums[0];
    dp[1] = max(dp[0] , dp[1]);

    for(int i = 2 ; i < nums.size() ; i++){
        
        int include = nums[i] + dp[i-2];
        int exclude = nums[i-1];

        dp[i] = max(include , exclude);
    }

    return dp[nums.size() -1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int index = 0;
    vector<int> dp (nums.size() , -1);
    

    return solve(nums,index, dp);
}


int main(){

    return 0;
}