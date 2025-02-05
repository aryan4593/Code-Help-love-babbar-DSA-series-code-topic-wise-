#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Nodde {
public:
    Nodde* left;
    Nodde* right;
    int data;
    
    Nodde(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Make comparator function public
class cmp {
public:
    bool operator()(Nodde* a, Nodde* b) {
        return a->data > b->data;
    }
};

class Solution {
    void traverse(Nodde* root, vector<string>& ans, string temp) {
        
        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }
        

        if (root->left) traverse(root->left, ans, temp + '0');
        if (root->right) traverse(root->right, ans, temp + '1');
    }
    
public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Nodde*, vector<Nodde*>, cmp> pq;
        
        for (int i = 0; i < N; i++) {
            Nodde* newNodde = new Nodde(f[i]);
            pq.push(newNodde);
        }
        
        while (pq.size() > 1) {
            Nodde* left = pq.top();
            pq.pop();
            
            Nodde* right = pq.top();
            pq.pop();
            
            Nodde* tempRoot = new Nodde(left->data + right->data);
            tempRoot->left = left;
            tempRoot->right = right;
            pq.push(tempRoot);
        }
        
        Nodde* root = pq.top();
        
        string temp = "";
        vector<string> ans;
        traverse(root, ans, temp);
        
    
        
        return ans;
    }
};