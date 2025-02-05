#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector <int>&v){
        int n = v.size()
        ;int j=n;
        for (int i =0;i<n/2;i++){
            int temp = v[j];
            v[j]=v[i];
            v[j]=v[i];
            // swap(v[i],v[j]);
            i++;j--;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v1;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if (nums[j]+nums[i]==target){
                    v1.push_back(i);
                    v1.push_back(j);
                }
   +3         }
        }
        reverse(v1);
        return v1;
    }
};
int main (){

    vector<int> v = {1,4,1,2,3,5};
    Solution s1;
    s1.reverse(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}