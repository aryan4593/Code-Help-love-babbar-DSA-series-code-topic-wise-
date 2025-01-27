#include<bits/stdc++.h>
using namespace std;
class Solution {
    int tab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int swapp = 0, noSwap =0;
        for(int index = n-1; index>=1 ; index--){
            int currSwap = swapp , currNoSwap = noSwap;
            for(int swapped = 1; swapped>=0 ; swapped--){
                int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];
                
                if(swapped){
                    swap (prev1,prev2);
                }

                // no swap
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans = noSwap;
                }
                // swap
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans = min(ans , 1 + swapp);
                }

                 if(swapped) currSwap = ans;
                 else currNoSwap = ans;
            }
            swapp = currSwap;
            noSwap = currNoSwap;

        }
        return min(swapp, noSwap);

    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // initialize prev of both index as -1
        nums1.insert(nums1.begin(), -1);  
        nums2.insert(nums2.begin(), -1);  
        
        bool swapped = false;
        return tab(nums1,nums2);
    }
};