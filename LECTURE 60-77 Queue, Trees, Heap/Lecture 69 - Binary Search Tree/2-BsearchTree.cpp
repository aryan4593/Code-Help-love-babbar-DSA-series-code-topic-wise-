#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertAtBst(Node* &root,int data){
    if(!root){
        root = new Node(data);
        return root;
    }
    if(data>root->data){
        root->right= insertAtBst(root->right,data);
    }
    
    if(data<=root->data) root->left= insertAtBst(root->left,data);
    return root;
}
void TakeInput (Node* &root){


    int data ;
    while (data!=-1)
    {
 cin>>data;
        insertAtBst(root,data);
    }
    
}

    #include <queue>

 
void levelOrderTraversal(Node *root){
    queue<Node *> q;

    q.push(root);
    q.push(NULL); 
    while (!q.empty()){
        Node *temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL); 
            }
        }

        else{
            cout << temp->data << " ";

            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right ){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root =NULL;
    cout<<"Give input\n";
    TakeInput(root);
    cout<<endl<<endl<<"printing BST"<<endl<<endl;
    levelOrderTraversal(root);
    return 0;
}

// 10 8 21 7 27 5 4 3