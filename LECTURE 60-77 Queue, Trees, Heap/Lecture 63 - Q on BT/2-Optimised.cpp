#include<iostream>
#include <utility>
#include<algorithm>
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

    pair<int,int> diameterFast(TreeNode* root){
        if(root ==NULL){
            //pair<diameter,height>
            //returning both height and diameter to reduce complexity
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first; //diameter
        int op2 = left.first;
        int op3 = left.second + right.second +1;

        pair<int,int> ans ;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second,right.second) +1;
         return ans;
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};


//op1 -> diameter lies in left subtree
// op 2 -> lies in right subtree
//op 3 => diameter is made from both left and right