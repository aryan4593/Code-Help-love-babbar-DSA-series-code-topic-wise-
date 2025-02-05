#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int, int>> month ; //day ,cost
        queue<pair<int, int>> week ; //day ,cost

        for(auto&day : days){

            // remove expire days

            while(!month.empty()  && month.front().first + 30 <= day){
                month.pop();
            }
            while(!week.empty()  && week.front().first + 7 <= day){
                week.pop();
            }

            // add cost for current day
            week.push({day , ans+costs[1]});
            month.push({day , ans+costs[2]});

            // update ans
            ans = min (ans + costs[0] , min(week.front().second ,month.front().second));

        }

        return ans;

    }
};