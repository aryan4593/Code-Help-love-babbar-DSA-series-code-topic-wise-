#include <iostream>
#include <climits>
struct TreeNode {
    long long int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
      return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    // Create a sample tree: 
    //       2
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    if (sol.isValidBST(root)) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is not a valid BST." << std::endl;
    }

    // Clean up the allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}