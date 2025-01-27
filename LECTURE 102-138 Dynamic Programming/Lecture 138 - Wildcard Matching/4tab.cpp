#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    
    bool tab(string&s, string&p){
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<int>>dp(m ,vector<int>(n,0));
        
        dp[0][0]  = true;
        // No need to handel 2nd cases as we are initializeing with false

        for(int j =1; j<p.size(); j++){
            bool flag = 1;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }


        for(int i=1; i<=s.size(); i++){
            for(int j=1;j<p.size(); j++){

                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    // consder * as empty string once and charector at other
                    dp[i][j] =  (dp[i-1][j]  || dp[i][j-1]);
                }
                else dp[i][j] =  false;

            }
        }
        
        return dp[s.size()][p.size()];

    }
public:
    bool isMatch(string &s, string &p) {
        return tab(s,p);
    }
};