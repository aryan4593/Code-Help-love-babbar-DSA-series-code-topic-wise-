#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int solve (int n , vector<int>&dp){
        if(n <= 1 ) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i =1 ; i <= n ;i++){
            //i is root node
            ans+= solve(i-1,dp) * solve(n-i,dp);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n,dp);
    }
};

// if i is node , there will be i - 1 nodes to it's left and n - i nodes to it's right
int main() {
    Solution solution;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Number of unique BSTs: " << solution.numTrees(n) << endl;
    return 0;
}