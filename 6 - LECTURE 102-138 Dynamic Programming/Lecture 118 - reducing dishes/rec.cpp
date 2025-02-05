#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&satis ,int index , int time){
        if(index == satis.size()) return 0;

        // include 
        int include = (time+1)*satis[index] +  solve(satis ,index+1 , time+1);
        
        // exclude
        int exclude = solve(satis , index+1 ,time);

        return max(include , exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        return solve(satisfaction ,0 , 0);
    }
};