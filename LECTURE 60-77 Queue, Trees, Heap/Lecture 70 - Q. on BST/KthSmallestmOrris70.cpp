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
class Solution {
    int morrisTraversal(TreeNode* root,int &i, int k){
        if(!root) return -1;
        TreeNode* curr = root;
        while(curr){
        if(curr->left){
            TreeNode* pred = curr->left;
            while(pred->right and pred->right != curr){
                pred = pred -> right;
            }
            if(pred->right){
                pred -> right = NULL;
                i++;
                if(k==i){
                    return curr->val;
                }
                curr = curr ->right;
            }
            else{
                pred -> right = curr;
                curr = curr ->left;
            }
        }
        else{
            i++;
            if(i==k) return curr->val;
            curr = curr->right;
        }

        }
        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return morrisTraversal(root,i,k);
    }
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    return root;
}

int main() {
    TreeNode* root = buildTree();
    Solution sol;
    int k = 1; // Change this value to test different k
    cout << "The " << k << "th smallest element is " << sol.kthSmallest(root, k) << endl;
    return 0;
}
