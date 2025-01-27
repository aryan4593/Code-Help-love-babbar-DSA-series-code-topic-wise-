#include<bits/stdc++.h>
using namespace std;
class Solution
{
    int solve(int n , int x , int y , int z){
        if(n ==0 ) return 0;
        if(n < 0) return INT_MIN;
        
        int ansX = 1 + solve(n-x ,x,y,z);
        int ansY = 1 + solve(n-y , x ,y ,z);
        int ansZ = 1 + solve(n-z , x,y,z);
        
        return max(ansX , max(ansY, ansZ));

    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int ans = solve(n , x , y , z);
        return (ans == INT_MIN) ? 0 : ans;
    }
};
