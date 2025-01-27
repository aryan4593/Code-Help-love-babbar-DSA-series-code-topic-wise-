
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=k;
        int n = nums.size();
        vector<int> temp(nums.size());

        for (int i =0;i<n;i++){
            int p = (i+k)%n;
            temp[p]=nums[i];

        }
        nums = temp;
        
    }
};
int main(){
    Solution s1;
    vector<int> v1;
    s1.rotate(v1,5);
}