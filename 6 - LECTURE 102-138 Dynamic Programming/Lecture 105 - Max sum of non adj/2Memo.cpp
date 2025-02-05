using namespace std;
#include <bits/stdc++.h> 
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
int maximumNonAdjacentSum(vector<int> &nums){

    int index = 0;
    vector<int> dp (nums.size() , -1);
    
    
    return solve(nums,index, dp);

}