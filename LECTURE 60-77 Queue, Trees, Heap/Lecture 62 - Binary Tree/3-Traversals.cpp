#include <iostream>
using namespace std;
#include <queue>
class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node *buildTree(node *root){
    cout << "enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root){
    queue<node *> q;

    q.push(root);
    q.push(NULL); // separator
    while (!q.empty()){
        node *temp = q.front();
        q.pop();
        if (temp == NULL){
            // means old level is completed
            cout << endl;
            if (!q.empty()){
                q.push(NULL); // separator
            }
        }

        else{
            cout << temp->data << " ";

            if (temp->left != NULL){
                q.push(temp->left);
            }
            if (temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    //base case 
    if(root ==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"printing  level order traversal "<<endl;
    levelOrderTraversal(root);
    cout<<"\n\n";

    cout<<"printing inorder traversal "<<endl;
    inOrder(root);
    cout<<"\n\n";
    cout<<"printing post traversal "<<endl;
    postOrder(root);
    cout<<"\n\n";
    cout<<"printing preOrder traversal "<<endl;
    preOrder(root);
    cout<<"\n\n";

    return 0;
}