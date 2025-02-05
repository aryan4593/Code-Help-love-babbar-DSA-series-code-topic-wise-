#include <iostream>
#include <queue>
#include <vector>
#include<map>
//breath frist traveersal
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
    TreeNode* mapping (TreeNode* root, int target,map<TreeNode*,TreeNode*>& m){
        TreeNode* targetNode = nullptr;

        queue<TreeNode*>q;
        q.push(root);
        m[root]=nullptr;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->val==target) targetNode = front;

            if(front->left){
                m[front->left] = front;
                q.push(front->left);
            }
            if(front->right){ 
                m[front->right]=front;
                q.push(front->right);
            }


        }

//also return target node
        return targetNode;
    }
    int infect(TreeNode* root, map<TreeNode*,TreeNode*>& m){
        map<TreeNode*,bool>visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root]=true;
        int ans =0;
        while(!q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i =0;i<size;i++){
                //process neighouring nodes
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left ]= true;
                    flag =1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right ]= true;
                    flag =1;
                }
                if(m[front] && !visited[m[front]]){
                    q.push(m[front]);
                    visited [m[front]] = true;
                    flag =1;
                }
            }
                if(flag) ans++;
        }
            return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        //create mapping of parent of every node
        //find towards start first
        // burn the tree in min time
        int ans =0;
        map<TreeNode*,TreeNode*>nodeToParent;
        map<TreeNode*, bool> visited;
        TreeNode* targetNode=mapping(root,start,nodeToParent);
        return infect(targetNode,nodeToParent);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    Solution sol;
    int time = sol.amountOfTime(root, 1);
    cout << "Time to burn the tree: " << time << endl;
    delete root;
    return 0;
}