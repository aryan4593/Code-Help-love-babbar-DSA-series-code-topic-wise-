#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& days, vector<int>& costs ,int index){
        if(index >= days.size()){
            return 0;
        }

        // 1-day
        int ans1 =costs[0] + solve(days ,costs ,index+1);

        // 7-days
        int i;
        for( i = index; i < days.size() && days[i] < days[index] + 7 ;i++);
        int ans2 = costs[1]+ solve(days ,costs ,i);

        // 30-days
        int j;
        for(j = index ; j < days.size() && days[j] < days[index]+30 ;j++);
        int ans3 = costs[2]+ solve(days ,costs, j);

        return min(ans1, min(ans2,ans3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days ,costs ,0);
    }
};

