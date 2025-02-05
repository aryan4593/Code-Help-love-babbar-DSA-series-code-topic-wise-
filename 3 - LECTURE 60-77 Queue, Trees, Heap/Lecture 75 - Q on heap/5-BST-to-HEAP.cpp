#include <iostream> 
#include<vector>
using namespace std;
	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};


void inorder(BinaryTreeNode* root, vector<int>&arr){
	if(!root) return;
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);
}
void popuLateWithPreOrder (BinaryTreeNode* &root,vector<int> arr, int &i ){
	if(!root) return;
	root->data = arr[i++];
	popuLateWithPreOrder(root->left, arr, i);
	popuLateWithPreOrder(root->right, arr, i);

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	inorder(root,arr);
	int i = 0;
	popuLateWithPreOrder(root, arr, i);
	return root;
}