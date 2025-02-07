#include<iostream>
#include<unordered_map>
using namespace std;
#include<vector>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_map<int,int> count;
        int maxi = INT32_MIN;
        for(auto i:nums){
             count[i]++;
            if(count[i] > maxi ){
                maxi = count[i];
            }
        }
        int ele = 0;
        for(auto i: count){
            if(i.second == maxi){
                ele++;
            }
        }

        return ele * maxi;
    }
};