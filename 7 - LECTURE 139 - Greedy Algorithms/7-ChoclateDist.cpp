#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        
        sort(a.begin() ,a.end());
        
        int i = 0; 
        int j = m-1;
        int ans = INT_MAX;
        while(j < a.size()){
            int diff = a[j] - a[i];
            
            ans = min(ans , diff);
            i++, j++;
        }
        
        return ans;
        
    }
};


int main() {
    vector<int> chocolates = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int students = 7;

    Solution s1;
    cout<<s1.findMinDiff(chocolates ,students);

    return 0;
}