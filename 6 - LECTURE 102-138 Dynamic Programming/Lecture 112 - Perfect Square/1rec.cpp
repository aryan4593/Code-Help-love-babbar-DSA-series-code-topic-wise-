#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n){
        if(n==0) return 0; //constrain
        // if(n==1) return 1;

        int ans = INT_MAX;
        for(int i = 1; i<= sqrt(n) ;i++){
            int iAns = 1 + solve(n-i*i) ;
            ans = min (ans , iAns);
        }
        return ans;
    }
public:
    int numSquares(int n) {
        return solve(n);
    }
};

// loop thro numbers from 1 to sqrt(n), check each combination min is the answer
int main(){}