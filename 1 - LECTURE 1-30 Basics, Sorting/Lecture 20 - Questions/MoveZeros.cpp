#include<iostream>
#include<vector>
using namespace std;
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i=0;
    for (int j =0;j<n;j++){
        if (nums[j]!=0)
        {
            swap(nums[i],nums[j]);
            i++;
        }
        
    }
    }

int main (){
    vector<int> v ={0,1,0,3,12};
    moveZeroes(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}