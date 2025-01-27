#include<iostream>
using namespace std;
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class info{
    public:
    int maxi; //max value of tree with root node
    int mini;
    bool isValid;
    int size;
};

info solve(TreeNode* root, int &ans){
    if(!root){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right,ans);

    info currNode;
    currNode.size = left.size + right.size +1;
    currNode.isValid = left.isValid && right.isValid && root->data>left.maxi && root->data <right.mini;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(left.mini,root->data);

    if(currNode.isValid) ans = max(ans,currNode.size);
    return currNode;
}

int largestBST(TreeNode * root){
    int maxSize=0;
    info temp = solve(root,maxSize);
    return  maxSize;
}