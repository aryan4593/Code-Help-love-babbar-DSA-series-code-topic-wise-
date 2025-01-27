#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2 , int index , bool swapped){
        if(index>=nums1.size()) return 0;

        int ans = INT_MAX;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swapped){
            // means last element were swapped so we have to change prev1 & prev2
            swap (prev1,prev2);
        }

        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            // no need to swap
            ans = solve(nums1,nums2,index+1, false);
        }
        // check if swap is possible
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans = min(ans , 1 + solve(nums1,nums2,index+1, true));
        }

        // note there can be a case where both no swap and swap will not happen 
        // it simply means we missed some index which was supposed to be swapped but we didn't
        return ans;

    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // initialize prev of both index as -1
        nums1.insert(nums1.begin(), -1);  
        nums2.insert(nums2.begin(), -1);  
        
        bool swapped = false;
        return solve(nums1,nums2,1,swapped);
    }
};