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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int inStart,int inEnd,map<int,int> &mapp){
        if(index>=preorder.size() || inStart>inEnd) return NULL;

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element); 
        int position = mapp[element];
        root ->left = solve(preorder,inorder,index,inStart,position-1,mapp);
        root->right = solve (preorder,inorder,index,position+1,inEnd,mapp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preIndex = 0;
       map<int,int>nodeToIndex;
       createMapping(inorder,nodeToIndex);
       TreeNode* ans = solve(preorder,inorder,preIndex,0,preorder.size()-1,nodeToIndex);
        return ans;
    }
};