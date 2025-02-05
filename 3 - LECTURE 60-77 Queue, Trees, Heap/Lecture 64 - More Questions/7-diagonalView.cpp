#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include <queue>

struct Node
{
    int data;
    Node* left, * right;
}; 
void helper(Node* root,int hd, map<int,vector<int>>&m){
    if(root==NULL) return;
    m[hd].push_back(root->data);
    helper(root->left, hd-1,m); //
    helper(root->right,hd,m);
}

vector<int> diagonal(Node *root)
{
    //when we traverse left decreaser hori dist by 1, and when we go right means it lies in 
    //same level so keep hd as it is 
   vector<int> ans;
   int hd = 0;
   map<int,vector<int>>m;
   helper(root,hd,m);
   for(auto i : m){
      ans.insert(ans.end(),i.second.begin(),i.second.end());
   }
   return ans;
}