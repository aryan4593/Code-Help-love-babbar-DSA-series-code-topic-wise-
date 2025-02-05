#include <iostream>
#include <vector>
#include <utility> // for std::pair
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    pair<int,int> solve(Node* root){
        if(!root){
            return {0,0}; 
        }
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns =solve (root->right);
        pair<int,int> res; //inc,exc
        res.first = rightAns.second + leftAns.second + root->data;
        res.second = max(leftAns.first,leftAns.second)+max(rightAns.first , rightAns.second);
        
        return res;
        }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans; //<include,exclude>
        ans = solve(root);
        return max(ans.first,ans.second);
        
    }
};