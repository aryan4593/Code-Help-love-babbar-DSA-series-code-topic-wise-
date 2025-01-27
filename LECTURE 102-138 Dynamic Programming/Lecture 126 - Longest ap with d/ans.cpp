#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int num = arr[i];
            int temp = 1 + mp[num - diff];
            mp[num]= temp;
            ans = max(ans , temp);
        }

        return ans;
    }
};