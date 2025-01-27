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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL && q == NULL) return true;
        if(!p && q) return false;
        if(!q && p) return false;

        //case 1 they are same

        bool left = isSameTree (p->left,q->left);
        bool right = isSameTree (p->right,q->right);
        bool val = p->val == q->val;
        
        if(left && right && val) return true;
        else return false;
        }
};