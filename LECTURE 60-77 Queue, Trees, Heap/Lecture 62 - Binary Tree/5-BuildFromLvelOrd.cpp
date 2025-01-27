#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q; 

    q.push(root);
    q.push(NULL);       //separator
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            // means old level is completed
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);   // separator
            }
        }

        else{
        cout<<temp->data<<" ";

        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }

        }
    }
}

node* BuildFromLevelOrder(node*& root){
    queue<node*> q;
    cout<<"Enter data for root "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"Enter Left node of "<<temp->data<<" ";
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node of "<<temp->data<<" ";
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }


    }
}

int main(){
    node*root =NULL;

    BuildFromLevelOrder(root);
    cout<<endl;
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);
    return 0;
}