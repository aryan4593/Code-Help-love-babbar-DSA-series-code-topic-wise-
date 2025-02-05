#include<bits/stdc++.h>
using namespace std;

class Solution {
        int lengthOfLIS(vector<int>& a) {
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i = 1 ; i < a.size() ; i++ ){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find indec of just bigger element in answer
                int index = lower_bound(ans.begin() ,  ans.end() , a[i]) - ans.begin(); // iterator diff
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
public:
    static bool compare (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];  // Sort second element in descending order
        return a[0] < b[0];  // Sort first element in ascending order
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> LIS;
        for(auto&vec : envelopes){
            LIS.push_back(vec[1]);
        }
        return lengthOfLIS(LIS);
        return 0;
    }
};
