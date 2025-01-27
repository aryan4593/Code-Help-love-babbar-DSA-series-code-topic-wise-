#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include <queue>

 struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    void helper(TreeNode* root, int level,vector<int> & ans){
        if(root==NULL) return;
        if(level == ans.size()){
            //means new  levle as there will be same level and answers
            ans.push_back(root->val);
        }
        helper(root->right, level+1, ans);
        helper(root->left,level+1,ans);


    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        helper(root,level,ans);
        return ans;
    }
};