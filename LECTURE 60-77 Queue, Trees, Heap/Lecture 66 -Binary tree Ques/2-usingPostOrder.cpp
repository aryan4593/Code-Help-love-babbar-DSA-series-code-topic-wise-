#include <iostream>
#include <vector>
using namespace std;
#include<map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void createMapping (vector<int> in,map<int,int>& mapp){
    for(int i =0;i<in.size();i++){
        mapp[in[i]] = i ;
    }
   }

   TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int st,int end,map<int,int>& mapp){
    if(st>end or index<0)  return nullptr;

    int ele = postorder[index--];
    int pos = mapp[ele];

    TreeNode* root = new TreeNode(ele);
    root->right = solve (inorder,postorder,index,pos+1,end,mapp);
    root->left = solve (inorder,postorder,index,st,pos-1,mapp);
    return root;
   }
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mapping;
        createMapping (inorder,mapping);
        int index = inorder.size()-1;
        TreeNode* ans = solve (inorder,postorder,index,0,index,mapping);
        return ans;
    }
};