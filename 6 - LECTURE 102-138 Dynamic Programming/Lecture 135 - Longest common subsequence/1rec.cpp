#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(string str1, string str2 , int i, int j){
        if(i == str1.size() or j == str2.size()) return 0;

        int ans = 0;

        // match
        if(str1[i] == str2[j])
        ans += 1 + solve(str1, str2 , i+1, j+1);
        else{
            // no match 
            // case 1, assume that char won't exist so move
            int case1 = solve(str1,str2,i,j+1);

            // case 2 check next if exist
            int case2 = solve(str1, str2,i+1, j);

            ans += max(case1, case2);
        }
        return ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        return solve(text1, text2,0,0);
    }
};

