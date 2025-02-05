#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    
    int getNodes(struct Node* root){
        if(!root ) return 0;

        int left = getNodes(root->left);
        int right = getNodes(root->right);
        return left + right + 1;
    }
    
    
    bool isCBT(struct Node* root, int i, int nodeCount){
        if(!root) return true;
        if(i >= nodeCount) return false;
        else {
            bool left = isCBT (root->left ,2*i +1, nodeCount);
            bool right = isCBT (root->right, 2*i + 2, nodeCount);
            
            return left and right;
        }
    }
    bool isMaxOrder(struct Node* root){
        cout<<"reached maxorder"<<endl;
        //type 1 - both child exist //type-2 leaf node //type 3 - only leaf child exist
        
        if(!root->left && !root->right) return true;
        if(!root->right) return root->data > root->left->data;
        else {
           return (root->data > root->left->data) && (root->data > root->right->data) &&
            isMaxOrder(root->left) && isMaxOrder(root->right);
        }
        
    }
    
public:
    bool isHeap(struct Node* tree) {
       
       return isCBT (tree,0,getNodes(tree)) and isMaxOrder(tree);
    }
};

int main() {
    // Creating the tree
    Node* root = new Node(1000);
    root->left = new Node(950);
    root->right = new Node(946);
    root->left->left = new Node(46);
    root->left->right = new Node(38);
    root->right->left = new Node(39);

    Solution sol;
    if (sol.isHeap(root)) {
        cout << "The tree is a heap" << endl;
    } else {
        cout << "The tree is not a heap" << endl;
    }

    return 0;
}
// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(N), where N is the number of nodes in the tree.*/

// Input: The root of the tree
// Output: Returns true if the tree is a heap, false otherwise
// The function isHeap takes the root of the tree as input and returns true if the tree is a heap, false otherwise.
// The function isHeap uses two helper functions, getNodes and isCBT, to check if the tree is a complete binary tree (CBT) and is in max-heap order.
// The getNodes function calculates the number of nodes in the tree.
// The isCBT function checks if the tree is a CBT by recursively checking the left and right subtrees.
// The isMaxOrder function checks if the tree is in max-heap order by recursively checking the parent and child nodes.
// The isHeap function combines the checks for CBT and max-heap order to determine if the tree is a heap.
// The main function creates a sample tree and calls the isHeap function to check if the tree is a heap.