#include<iostream>
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
public:
    int count =0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight= maxDepth(root->left);
        int rightHeight= maxDepth(root->right);
        count = max(leftHeight,rightHeight)+1;
        return count;
    }
};