#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>&obs, int currLane , int pos){
        if(pos == obs.size() -1) {
            return 0;
        }

        if(obs[pos+1] != currLane){
            return solve(obs , currLane , pos+1);
        }
        else{
            int ans = INT_MAX;
            for(int i =1 ; i<=3 ;i++){

                if(i != currLane && obs[pos] != i )
                    ans = min(ans , 1 + solve(obs , i, pos));
            }
            return ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles , 2 , 0);
    }
};
int main(){
    
}