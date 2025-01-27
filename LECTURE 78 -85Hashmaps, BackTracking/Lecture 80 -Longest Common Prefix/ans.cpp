#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount = 0;
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
            root->childCount++;
            insertUtill(child, word.substr(1));
        }

    }
    void insert(string word) {
        insertUtill(head,word);
    }
    
    void LongestCommPre(string str , string &ans){
        for(int i = 0 ; i<str.length();i++){
            char ch = str[i];

            if (head->childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                head = head->children[index];
            }
            else break;

            if(head->isTerminal) break;
        }

    }
    

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t =new Trie;

        for(auto i : strs){
            t->insert(i);
        }

        string first = strs[0], ans = "";
        t->LongestCommPre(first,ans);

        return ans;
    }
};