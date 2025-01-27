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
    int height(TreeNode* root){
        if(root ==NULL) return 0;
        int lh = height(root->left);
        int rh = height (root->right);
        int h = max(lh,rh)+1;
        return h;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL) return 0;
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree (root->right);
        int op3 = height(root->left )+ height(root->right);

        int ans = max(op1, max(op2,op3));
         return ans;
    }
};


//op1 -> diameter lies in left subtree
// op 2 -> lies in right subtree
//op 3 => diameter is made from both left and right



// complixity of this is O(n**2)