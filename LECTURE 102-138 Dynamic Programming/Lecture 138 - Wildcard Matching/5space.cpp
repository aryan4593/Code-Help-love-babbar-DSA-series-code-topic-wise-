#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    
    bool tab(string&s, string&p){
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<int>>dp(m ,vector<int>(n,0));
        vector<int>prev (n,0); 
        vector<int>curr (n,0); 
        prev[0]  = 1;
        // No need to handel 2nd cases as we are initializeing with false

        for(int j =1; j<=p.size(); j++){
            bool flag = 1;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }


        for(int i=1; i<=s.size(); i++){
            for(int j=1;j<=p.size(); j++){

                if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if(p[j-1] == '*'){
                    // consder * as empty string once and charector at other
                    curr[j] =  (prev[j]  || curr[j-1]);
                }
                else curr[j] =  false;
            }
            prev = curr;
        }
        
        return prev[p.size()];

    }
public:
    bool isMatch(string &s, string &p) {
        return tab(s,p);
    }
};