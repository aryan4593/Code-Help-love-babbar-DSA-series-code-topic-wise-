#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int st, int end){
        if(st >= end) return 0;

        int ans = INT_MAX;

        for(int i =  st ; i <= end ; i++){
            int lower = solve(st,i-1);
            int higher = solve(i+1, end);
            
            // we assume that answer is wrong
            int tempAns = i + max (lower , higher);

            ans = min(ans, tempAns);
        }
        return ans;
    }
public:
    int getMoneyAmount(int n) {
        return solve(1,n);
    }
};
int main() {
    // Your code here

    return 0;
}