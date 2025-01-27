//alsoo called as Spiral traversal

#include<iostream>
#include<queue>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result; 
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while(!q.empty()){
            //process level
            int size =q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                int index = leftToRight ? i : size -i-1; 
                //index front start if left to right is true else from end
                ans [index] = frontNode->val;

                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
                leftToRight = !leftToRight; //flow change
                
                    result.push_back(ans);
                
                
        }
        return result;
    }
};