#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& values ,int i ,int j){
        if(i+1 == j){
            //means we have only 2 nodes
            return 0;
        }

        int ans = INT_MAX;
        for(int k = i+1 ; k < j ;k++){
            int temp = values[i]*values[j]*values[k] + solve(values ,i , k) + solve(values ,k , j);
            ans = min(ans ,  temp);
        }

        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values ,0 , n-1);
    }
};