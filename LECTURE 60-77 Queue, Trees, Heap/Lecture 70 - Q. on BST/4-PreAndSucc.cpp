// predcessor -> left subree's largest element 
// successor ->right subtree's smallest element
#include <iostream>
#include <utility>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pre = -1, suc = -1;
    TreeNode* temp = root;

    // First, find the node with the key
    while (temp) {
        if (temp->data == key) break;  // Found the key
        if (key < temp->data) {
            suc = temp->data;  // Current node could be the successor
            temp = temp->left;
        } else {
            pre = temp->data;  // Current node could be the predecessor
            temp = temp->right;
        }
    }

    // If the key is not found in the tree, return the current pre and suc
    if (!temp) return {pre, suc};

    // Find the predecessor (max value in the left subtree)
    TreeNode* leftTree = temp->left;
    while (leftTree) {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find the successor (min value in the right subtree)
    TreeNode* rightTree = temp->right;
    while (rightTree) {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pre, suc};
}
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    int key = 10;
    pair<int, int> result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}