#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // min
        sort(candies, candies + N);
        
        int mini = 0;
        int i=0, j = N - 1;
        
        while(i<=j){
            mini +=candies[i];
            i++;
            j-=k;
        }
        
        // maxi
        int maxi = 0;
        j = N- 1, i = 0;
        while(i<=j){
            maxi += candies[j];
            j--;
            i+=k;
        }
        
        vector<int>ans = {mini,maxi};
        
        return ans;
        
    }
};
int main() {
    // Your code here

    return 0;
}