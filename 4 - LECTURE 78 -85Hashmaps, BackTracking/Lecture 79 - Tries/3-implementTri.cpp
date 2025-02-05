#include<iostream>
#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal = false;
    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* head;
    Trie(){
        head = new TrieNode('\0');
    }
    void insertUtill(TrieNode* root , string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        if(root->children[index] ){
            TrieNode* child = root->children[index];
            insertUtill(child, word.substr(1));
        }
        else{
            TrieNode* child = new TrieNode(word[0]);
            root->children[index] = child;
            insertUtill(child, word.substr(1));
        }

    }
    void insert(string word) {
        insertUtill(head,word);
    }
    
    bool searchUtill(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] != nullptr){
            TrieNode* child = root->children[index];
            return searchUtill(child, word.substr(1));
        }
        else{
            return false;
        }
    }
    bool search(string word) {
        return searchUtill(head, word);
    }
    
    bool startsWithUtill (TrieNode* root , string prefix){
        if(prefix.length()==0){
            return true;
        }
        int index = prefix[0] - 'a';

        if(root->children[index]){
            TrieNode* child = root->children[index];
            return startsWithUtill(child , prefix.substr(1));
        }
        else return false;
    }
    bool startsWith(string prefix) {
        return startsWithUtill(head , prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */