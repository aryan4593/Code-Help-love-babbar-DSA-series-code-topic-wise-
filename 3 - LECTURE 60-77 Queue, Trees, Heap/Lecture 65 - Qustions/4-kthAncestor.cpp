struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node *root, int &k, int node){
    if(root == NULL) return NULL;
    if(root->data == node ){
        return root;
    }
    
    Node* left = solve (root->left,k,node);
    Node* right = solve (root->right,k,node);
    if(left && !right){
        k --;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return left;
    }
        if(!left && right){
        k --;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve (root,k,node);
    if(!ans || ans->data == node) return -1;
    else return ans->data;
}