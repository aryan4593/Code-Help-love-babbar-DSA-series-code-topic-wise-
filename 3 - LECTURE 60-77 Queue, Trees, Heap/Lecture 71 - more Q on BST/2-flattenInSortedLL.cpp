#include<iostream> 
#include<vector>
using namespace std;
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void inorder(TreeNode<int>*root,vector<int> &v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> v;
    inorder( root,v);
    if(v.empty()) return nullptr;
    TreeNode<int> * ans = new TreeNode<int> (v[0]);
    TreeNode<int> * curr = ans;
    curr->left = nullptr;
    for(int i = 1;i<v.size();i++){
        TreeNode<int>* temp = new TreeNode<int> (v[i]);
        curr->left = nullptr;
        curr->right = temp ;
        curr = curr->right;
    }

    curr->right = curr->left = nullptr;

    return ans;
}
