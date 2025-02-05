#include<bits/stdc++.h>
using namespace std;
class Solution {
    int tab(string &str1, string &str2){
        int n=str1.size();
        int m=str2.size();
        
        vector<vector<int>> dp(n , vector<int>(m,0));
        vector<int> next(m, 0);
        vector<int> curr(m, 0);
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int ans = 0;
                // match
                if(str1[i] == str2[j])
                    ans += 1 + next[j+1];
                else{
                    // no match 
                    // case 1, assume that char won't exist so move
                    int case1 = curr[j+1];

                    // case 2 check next if exist
                    int case2 = next[j];

                    ans += max(case1, case2);
                }
               curr[j] =  ans;
            }
            next = curr;
        }
        return curr[0];

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return tab(text1, text2);
    }
};
