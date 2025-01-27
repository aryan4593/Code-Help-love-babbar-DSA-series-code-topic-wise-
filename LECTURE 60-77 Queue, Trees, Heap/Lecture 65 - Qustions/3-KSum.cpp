#include<iostream>
using namespace std;
#include<vector>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    void solve (TreeNode* root, int target, int &count,vector<int> path){
        //base case
        if(root==NULL) 
            return ;

        path.push_back(root->val);

        solve(root->left,target,count,path);
        solve(root->right,target,count,path);

        //check k sum;
        long long int sum = 0;
        for(int i = path.size()-1;i>=0;i--){
            sum+=path[i];
            if(sum==target)
                count++;
            
        }
        path.pop_back();

    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count =0;
        solve (root,targetSum,count,path);
        return count;
    }
};