using namespace std;
#include <bits/stdc++.h> 

void solve(vector<int> &nums , int i , int&ans , int sum){
    if(i >= nums.size()){
        ans = max(ans,sum);
        return;
    }

    // include
    solve(nums, i+2 , ans , sum+nums[i]);

    // exclude 
    solve(nums,  i+1, ans , sum);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int index = 0;
    int ans;
     solve(nums,index,ans,0);

    return ans;
}