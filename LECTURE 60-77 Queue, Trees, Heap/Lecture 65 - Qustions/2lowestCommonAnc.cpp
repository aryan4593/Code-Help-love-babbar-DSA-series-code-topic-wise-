#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        if (!leftAns && rightAns)
        {
            return rightAns;
        }
        else if (leftAns && !rightAns)
            return leftAns;
        else if (leftAns && rightAns) 
            return root;
        else
            return NULL;
    }
};

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;
    Solution solution;
    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != NULL)
    {
        cout << "The Lowest Common Ancestor of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
