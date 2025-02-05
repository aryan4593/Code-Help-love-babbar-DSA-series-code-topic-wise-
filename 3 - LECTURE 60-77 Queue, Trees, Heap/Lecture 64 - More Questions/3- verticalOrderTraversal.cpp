#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

 //tip - (x,y) => x is level and y is Horizontal distance
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //we have to create mapping for horizontal distance with level wise nodes
        map<int, map<int,vector<int>>> nodes; //map<Hori-dist, map<level,nodes>>

        queue<pair<TreeNode*,pair<int,int>>>q; //queue for Level order traversal, Node*,<HoriDist,levle>
        vector<vector<int>> results;
        if(root==NULL)  return results;

        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp = q.front(); //front node of queue
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;  //horizontal distance
            int level = temp.second.second;

            nodes[hd][level].push_back(frontNode->val);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left,make_pair(hd-1,level+1))); //when we go left hd-=1
            if(frontNode->right)
                q.push(make_pair(frontNode->right,make_pair(hd+1,level+1))); //when we go right hd+=1
            
        }

                vector<int> ans ;
        for(auto i : nodes){
                ans.clear();
            for(auto j: i.second){
                sort(j.second.begin(), j.second.end()); 
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
                results.push_back(ans);
        }

        return results;

    }
};