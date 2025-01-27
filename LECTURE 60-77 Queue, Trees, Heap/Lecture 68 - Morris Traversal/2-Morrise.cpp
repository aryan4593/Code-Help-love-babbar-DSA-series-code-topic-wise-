#include<iostream>
using namespace std;    
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void morrisTraversal(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            cout<<"root->val";
            curr = curr->right;
        }
        else{
            TreeNode* predecessor = curr->left;
            while(predecessor->right and predecessor->right!=curr ) predecessor=predecessor->right;
            if(!predecessor->right){
                predecessor->right = curr;
                curr = curr->left;
            }
            else{
                predecessor->right = nullptr;
                cout<<curr->val;
                curr = curr->right;
            }
        }
    }
}


void mt(TreeNode* root){
   TreeNode*curr = root;

   while(curr){
    if(!curr->left){
        cout<<curr->val;
        curr = curr->right;
    }
    else{
        TreeNode* predissor = curr->left;
        while(predissor->right and predissor!=curr){
            predissor= predissor->right;
        }
        if(predissor->right==NULL){
            predissor->right = curr;
        }
        else{
            predissor->right=NULL;
            cout<<curr->val;
            curr= curr->right;
        }
    }
   }
}
int main (){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    morrisTraversal(root);

    return 0;
}