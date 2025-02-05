#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int solve(string word1, string word2, int i , int j ,vector<vector<int>> &dp){
        if(j== word2.size()) return word1.size() - i; //matched, remaining should be deleted
        if(i==word1.size()){
            return word2.size() - j; // means we need to insert those many charector
        } 

        int ans = 0;
        if(dp[i][j] !=-1) return dp[i][j];
        // case1 charecter matched
        if(word1[i] == word2[j]){
            return solve(word1, word2 , i+1 ,j+1,dp);
        }
        else{
            // case 2 insert
            int case2 = 1 + solve(word1, word2 , i,j+1,dp);

            // case 3 delete
            int case3 = 1 + solve(word1, word2 , i+1 , j,dp);

            // case 3 replace
            int case4 = 1 + solve(word1, word2, i+1, j+1,dp);

            ans = min(case2 , min(case3 ,case4));
        }

        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size() ,l2 = word2.size();
        vector<vector<int>> dp(l1+1 , vector<int>(l2+1 ,-1));
        return solve(word1, word2, 0, 0 , dp );
    }
};

int main() {
    Solution solution;
    string word1 = "intention";
    string word2 = "execution";
    int result = solution.minDistance(word1, word2);
    cout << "The minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << result << endl;
    return 0;
}