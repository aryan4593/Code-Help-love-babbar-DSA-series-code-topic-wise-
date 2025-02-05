#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    // only p will contain * and ?
    bool solve(string s, string p, int i , int j){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;

        if(i<0 && j>=0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?') return solve(s,p,i-1,j-1);
        else if(p[j] == '*'){
            // consder * as empty string once and charector at other
            return solve(s,p,i-1,j) || solve(s,p,i,j-1);
        }
        else return false;

    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        return solve(s,p,m-1,n-1);
    }
};