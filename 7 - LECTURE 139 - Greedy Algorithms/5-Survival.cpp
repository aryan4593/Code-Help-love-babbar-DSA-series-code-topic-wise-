#include <iostream>
using namespace std;
// corrected answer
class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        if(M > N) return -1; //you can't buy required food
        if(6 * N < 7 * M && S > 6) return -1; //you will die on sunday
        
        int requiredFood = S * M;
        int ans = 0;
        if(requiredFood % N == 0) ans = requiredFood / N;
        else ans = requiredFood / N + 1;
        
        return ans; 
    }
};

int main() {
    // Your code here

    return 0;
}