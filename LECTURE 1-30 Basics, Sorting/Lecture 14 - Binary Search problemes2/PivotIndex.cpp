#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sumBefore(vector<int>& nums,int i){
        int sum =0;
        for (int j =0;j<i;j++){
            sum = sum + nums[j];
        }
        return sum;
    }
    int sumAfter (vector<int>& nums,int i){
        int sum =0;
        int size = nums.size();
        for (int j =i+1;j<size;j++){
            sum = sum + nums[j];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();

        for (int i =2;i<size;i++){
            cout<<"sumbefore is "<<sumBefore(nums,i)<<endl;
            cout<<"sumAfter is "<<sumAfter(nums,i)<<endl;
            if (sumBefore(nums,i)== sumAfter(nums,i)){
                return i;
            }
        }
        return -1;
    }
};
int main (){
    vector<int>  nums = {1,7,3,6,5,6};
    Solution s1;
    cout<<s1.pivotIndex(nums);
    return 0;
}