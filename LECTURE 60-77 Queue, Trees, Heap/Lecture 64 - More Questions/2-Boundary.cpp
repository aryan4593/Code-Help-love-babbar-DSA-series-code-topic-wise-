#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 


class Solution {
    void leafNodes(Node * root , vector<int> & ans){
        if(root==NULL) return;
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
            
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    
    void traverseRight(Node* root, vector<int> & ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) return;// leaf Node
        
        if(root->right)
            traverseRight(root->right, ans );
            
        else traverseRight(root->left,ans);
        //backtracking
        ans.push_back(root->data);
    }
    
    
    void traverseLeft(Node*root , vector<int> &ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left,ans);
        else traverseLeft(root->right,ans);
    }
    
    
public:
    
    vector <int> boundary(Node *root)
    {
        //part 1 print left part except last leaf node
        //part 2 print all leaf nodes
        //part 3 print all right part from bottom to top except leaf node
        
        //part 1
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->data);
        
        traverseLeft(root,ans);
        
        //traverse leaf nodes
        //of left subTrees
        leafNodes(root->left,ans);
        // for right subtree
        leafNodes(root->right,ans);
        
        //traverse right part
        traverseRight(root->right,ans);
            
        return ans;
        
        
    }
};