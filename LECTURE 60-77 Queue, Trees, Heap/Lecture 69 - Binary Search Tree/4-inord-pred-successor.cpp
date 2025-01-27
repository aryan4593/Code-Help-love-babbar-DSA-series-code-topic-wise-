#include <iostream>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the inorder predecessor
Node* findPredecessor(Node* root) {
    Node* current = root->left;
    while (current && current->right) {
        current = current->right;
    }
    return current;
}

// Function to find the inorder successor
Node* findSuccessor(Node* root) {
    Node* current = root->right;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

// Function to find the inorder predecessor and successor
void findPredecessorSuccessor(Node* root, Node*& predecessor, Node*& successor, int key) {
    if (!root) return;

    if (root->data == key) {
        // If the key is found, find the predecessor and successor
        if (root->left) {
            predecessor = findPredecessor(root);
        }
        if (root->right) {
            successor = findSuccessor(root);
        }
    } else if (key < root->data) {
        // If the key is smaller than root's data, go to the left subtree
        successor = root;
        findPredecessorSuccessor(root->left, predecessor, successor, key);
    } else {
        // If the key is greater than root's data, go to the right subtree
        predecessor = root;
        findPredecessorSuccessor(root->right, predecessor, successor, key);
    }
}

// Utility function to insert a new node with given key in BST
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

// Driver code
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 65;
    Node* predecessor = nullptr;
    Node* successor = nullptr;

    findPredecessorSuccessor(root, predecessor, successor, key);

    if (predecessor) {
        cout << "Predecessor is " << predecessor->data << endl;
    } else {
        cout << "No Predecessor" << endl;
    }

    if (successor) {
        cout << "Successor is " << successor->data << endl;
    } else {
        cout << "No Successor" << endl;
    }

    return 0;
}

// Inorder Predecessor and Successor
// In a Binary Search Tree (BST), the inorder predecessor of a node is the previous node in the inorder traversal of the BST. 
// Similarly, the inorder successor of a node is the next node in the inorder traversal of the BST.

// Example:
// Consider the following BST:
//         50
//        /  \
//      30    70
//     /  \  /  \
//    20  40 60  80

// Inorder Traversal: 20, 30, 40, 50, 60, 70, 80

// For node 50:
// Inorder Predecessor: 40
// Inorder Successor: 60

// For node 30:
// Inorder Predecessor: 20
// Inorder Successor: 40

// For node 70:
// Inorder Predecessor: 60
// Inorder Successor: 80

// For node 20 (smallest element):
// Inorder Predecessor: None
// Inorder Successor: 30

// For node 80 (largest element):
// Inorder Predecessor: 70
// Inorder Successor: None