#include<iostream>
using namespace std;
#include<vector>

void  solve (vector<int>nums,vector<int> output, int index,vector <vector<int>> &ans) {
    if (index>nums.size ()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums,output,index+1,ans);

    //include
    int temp = nums[index];
    output.push_back(temp);
    solve(nums,output,index+1,ans);


}

int main (){

    return 0;
}