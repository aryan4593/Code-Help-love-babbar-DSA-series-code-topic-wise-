#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int dice , int faces , int target){
        if(target<0) return 0;
        if(target != 0 && dice == 0) return 0;
        if(target == 0 && dice!=0) return 0;
        if(dice == 0 && dice == 0) return 1; 

        int ans = 0;
        for(int i = 1 ;i <= faces ;i++){
            ans+= solve(dice-1, faces ,target-i);//as we are using 1 dice and decrementing target by i
        }

        return ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n ,k , target);
    }
};