#include<bits/stdc++.h>
using namespace std;
class Solution {

    int tab(vector<int>&obs){
        int n = obs.size()-1 ;
        vector<int>curr(4,1e9);
        vector<int>next(4,1e9);

        // base case
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int pos = n-1; pos>=0 ;pos--){
            for(int currLane=1; currLane<= 3;currLane++){
                if(obs[pos+1] != currLane){
                    curr[currLane] =  next[currLane];
                }
                else{
                    int ans = INT_MAX;
                    for(int i =1 ; i<=3 ;i++){

                        if(i != currLane && obs[pos] != i )
                            ans = min(ans , 1 +  next[i]);
                    }
                    curr[currLane]=ans;
                }
            }
            next = curr;
        }

        return min(next[2] , 1+ min (next[1] ,next[3]));


    }
public:
    int minSideJumps(vector<int>& obstacles) {
       return tab(obstacles);
    }
};

int main(){}