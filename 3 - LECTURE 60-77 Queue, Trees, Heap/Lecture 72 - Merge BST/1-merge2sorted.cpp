#include <iostream>
#include <vector>
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
void inorder(TreeNode* root,vector<int> & v){
    if(!root) return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}


vector<int> mergeArrays(vector<int> v1,vector<int> v2){
    int i = 0,j=0;
    vector<int> ans;
    while(i < v1.size() and j< v2.size()){
        if(v1[i]<=v2[j]) {
            ans.push_back(v1[i++]);
        }
        else ans.push_back(v2[j++]);
    }

    while(i < v1.size())
        ans.push_back(v1[i++]);
    
    while(j < v2.size())
        ans.push_back(v2[j++]);

    return ans;
    
}

TreeNode*  inorderToBST(vector<int> arr,int s, int e){
    if(s>e) return nullptr;
    
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = inorderToBST( arr, s, mid-1);
    root->right = inorderToBST(arr, mid+1, e);
    return root;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> v1,v2;
    inorder(root1,v1);
    inorder(root2,v2);
    vector<int> ans = mergeArrays(v1,v2);
// /return inorderToBST(ans,0,ans.size()-1);
    return ans;
}