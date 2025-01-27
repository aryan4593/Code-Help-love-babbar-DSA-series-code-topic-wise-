#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include <queue>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    vector<int> bottomView(Node *root)
    {
       //similar to last question but we have to hide other nodes expcept first of Hori-level
       vector<int> ans;
       
       if(root ==NULL) return ans;
       
       map<int,int>topNode; //horizontal dist,mapping
       queue<pair<Node*, int>>q; //horizontal distance
       q.push(make_pair(root,0));
       
       while(!q.empty()){
           pair<Node*, int> temp =q.front();
           q.pop();
           Node*frontNode = temp.first;
           int hd= temp.second;
           
               topNode[hd] = frontNode->data;
           
           if(frontNode->left)
                q.push(make_pair(frontNode->left,hd-1));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right,hd+1));
       }
       
       for(auto i:topNode){
           ans.push_back(i.second);
       }
       
       return ans;
    }

};