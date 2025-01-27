#include <iostream>
using namespace std;

class Solution {

    int solve (int n ){
        if(n <= 1 ) return 1;

        int ans = 0;
        for(int i =1 ; i <= n ;i++){
            //i is root node
            ans+= solve(i-1) * solve(n-i);
        }
        return ans;
    }
public:
    int numTrees(int n) {
        return solve(n);
    }
};

// if i is node , there will be i - 1 nodes to it's left and n - i nodes to it's right

int main() {
    // Your code here

    return 0;
}