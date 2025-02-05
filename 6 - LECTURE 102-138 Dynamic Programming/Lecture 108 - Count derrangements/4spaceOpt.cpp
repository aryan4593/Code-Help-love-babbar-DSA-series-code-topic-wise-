#include<bits/stdc++.h>
using namespace std;
class Solution {

    
    int solve(int n){
        if(n==1) return 0;
        int prev1 = 0;
        int prev2 =1;
        
        for(int i = 3; i <=n ; i++){
            int ans = (i-1) * (prev1+ prev2);
            
            prev1 = prev2;
            prev2 = ans;
        }
        return prev2;
    }
  public:
    int countDer(int n) {

        int ans = solve(n);
        return ans;
    }
};

int main(){
    
}