#include <iostream>
using namespace std;

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // if(M > N) return -1;
        
        int sunday = S / 7;
        int buyingDays = S - sunday;
        int totalFood  = S*M;
        
        int ans =  (totalFood % N == 0) ? (totalFood/N) : (totalFood/N)  + 1;
        
        return (ans > buyingDays) ? -1 : ans;

    }
};

int main() {
    // Your code here

    return 0;
}