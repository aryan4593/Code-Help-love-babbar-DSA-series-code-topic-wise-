#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isBST (TreeNode* root,long long int mini,long long int maxi){
        if(!root) return true;
        if(root->val >mini and root->val < maxi){
            bool left = isBST(root->left, mini,root->val);
            bool right = isBST (root->right,root->val,maxi);
            return left && right;
        }
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        if(!root->left and !root->right) return true;
      return isBST(root, INT32_MIN, INT32_MAX);
    }
};