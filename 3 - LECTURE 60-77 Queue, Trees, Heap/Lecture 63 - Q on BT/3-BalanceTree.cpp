#include<iostream>
#include<utility>
using namespace std;


  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    pair<bool,int> helper(TreeNode* root){
        if(root == NULL){
            //bool, height
            return {true,0};
        }
        pair<bool,int> left = helper(root->left);
        pair<bool,int> right = helper(root->right);

        bool diff = abs(left.second - right.second)<=1; //difference must be <=1

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1; //for height

        //for bool value
        if(left.first && right.first && diff) ans.first = true;  
        else ans.second = false;

        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};