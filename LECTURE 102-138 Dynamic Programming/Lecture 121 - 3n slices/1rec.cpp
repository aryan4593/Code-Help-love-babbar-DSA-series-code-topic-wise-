#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(vector<int>& slices , int index , int n){
        if(n == 0  || index >=slices.size()) return 0;

        int take = slices[index] + solve(slices, index+2 , n-1);
        int notTake = solve(slices , index+1 ,n);

        return max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        // we don't eat first slice
        int case2 = solve(slices , 1, k/3);

        // we eat 1st slice , means can't eat last
        slices.pop_back();
        int case1 = solve(slices ,0 , k/3); //as 3n isze so we will eat k/3 slices

        return max(case1,case2);
    }
};
int main(){
    
}