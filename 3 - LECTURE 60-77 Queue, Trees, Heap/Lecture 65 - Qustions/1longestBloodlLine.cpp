#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    void solve (Node* root, int sum,int &maxSum,int len,int &maxLen){
        if(root==NULL){
            if(len > maxLen){
                maxSum = sum;
                maxLen = len;
            }
            else if (len == maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }
        
        sum+=root->data;
        solve(root->left,sum,maxSum,len++,maxLen);
        solve(root->right,sum,maxSum,len++,maxLen);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen =0;
        int sum =0;
        int maxSum = INT8_MIN;
        solve (root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};