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
    TreeNode* flat(TreeNode* &root){
        if(!root) return NULL;
        TreeNode* left = flat(root->left);
        TreeNode* right= flat(root->right);
        root->right = left;
        TreeNode* temp = root;
        while (temp->right ){
            temp = temp->right;
        }
        temp->right = right;

        return root;
    }
public:
    void flatten(TreeNode* root) {
        flat (root);
    }
};

int main() {
    // Create the tree nodes
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5, nullptr, node6);
    TreeNode* node2 = new TreeNode(2, node3, node4);
    TreeNode* root = new TreeNode(1, node2, node5);

    // Create the solution object and flatten the tree
    Solution sol;
    sol.flatten(root);

    // Print the flattened tree
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }

    // Clean up the allocated memory
    curr = root;
    while (curr) {
        TreeNode* next = curr->right;
        delete curr;
        curr = next;
    }

    return 0;
}