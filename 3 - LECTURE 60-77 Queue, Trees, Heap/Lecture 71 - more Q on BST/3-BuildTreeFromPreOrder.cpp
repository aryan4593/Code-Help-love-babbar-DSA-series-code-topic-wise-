#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0) ,  left(nullptr) ,  right(nullptr) {}
    TreeNode(int x) : val(x) ,  left(nullptr) ,  right(nullptr) {}
    TreeNode(int x ,  TreeNode *left ,  TreeNode *right) : val(x) ,  left(left) ,  right(right) {}
};
class Solution {
    TreeNode* solve(vector<int>& preorder , int mini , int maxi , int &i ){
        if(i>=preorder.size()) return nullptr;
        
        if(preorder[i]<mini or preorder[i]>maxi){
            return NULL;
        }
        TreeNode* root = new TreeNode (preorder[i++]);
        root->left = solve (preorder , mini , root->val , i);
        root->right = solve(preorder , root->val , maxi , i);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        int i = 0;
        return solve(preorder , INT16_MIN , INT16_MAX , i);
    }
};