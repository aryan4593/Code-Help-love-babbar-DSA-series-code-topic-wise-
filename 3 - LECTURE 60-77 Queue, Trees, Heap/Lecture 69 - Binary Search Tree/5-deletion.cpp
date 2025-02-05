// 3 cases -
//     1. leaf node to delete -:>just delete and send nullptr above
//     2. one child to delete -> just send child node above
//     3. node to del have 2 child-> 2ways = 1st  replace deleted with max val from left    2nd ->replace with min val of right subtree

#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main(){

    return 0;
}