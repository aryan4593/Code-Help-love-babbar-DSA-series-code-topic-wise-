
#include<bits/stdc++.h>
using namespace std;
class Solution {
    // int solve (vector<int>& a){

    // }
public:
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
};