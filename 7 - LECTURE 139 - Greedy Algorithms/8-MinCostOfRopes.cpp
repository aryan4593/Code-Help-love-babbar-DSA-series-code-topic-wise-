#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>,  greater<int> > minHeap;
        
        for(auto&num : arr) minHeap.push(num);
        int cost = 0;
        while(minHeap.size() > 1){
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            
            int tempCost = first + second;
            
            minHeap.push(tempCost);
            cost += tempCost;
        }
        
        return cost;
    }
};
int main() {
    vector<int> ropes = {4, 3, 2, 6};
    Solution s1;
    cout << "Minimum cost to connect ropes: " << s1.minCost(ropes) << endl;
    return 0;
}