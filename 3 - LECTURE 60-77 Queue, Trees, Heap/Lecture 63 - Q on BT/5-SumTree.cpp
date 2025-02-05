#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
    pair<bool,int> helper (Node* root){
        if(root == NULL) return {true,0};
        //for leaf node we don't have to check
        if(!root->left && !root->right) return {true,root->data};
        
        pair<bool,int> left = helper(root->left);
        pair<bool,int> right = helper (root->right);
        int sum =left.second + right.second;
        bool condition = sum == root->data;
        pair<bool,int> ans;
        ans.first = (left.first && right.first && condition);
        ans.second = sum*2;
        return ans;
        
    }
  public:
    bool isSumTree(Node* root) {
       return helper(root).first;

    }
};