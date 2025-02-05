#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children [26]; //array of children a-z
    bool isTerminal;

    TrieNode(char ch){
        char data = ch;
        for(auto i:children){
            i = nullptr;
        }
    }

};

 class Trie{

    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }


    void insertUtill(TrieNode* root , string word){
        if(word.length()==0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] !=NULL){
            //present
            child = root->children[index];

        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtill(child , word.substr(1));
    }

    void insertWord(string word){
        insertUtill(root , word);
    }

    bool searchUtill(TrieNode* root , string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';

        if(root->children[index]){
            TrieNode* child = root->children[index];
            searchUtill(child, word.substr(1));
        } 
        else return false;
    }
    bool search(string word){
        return searchUtill(root , word);
    }

    void deleteWord(TrieNode* root , string word){
        if(word.length()== 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0]- 'A';
            TrieNode *child = root->children[index];
            
        deleteWord(child,word.substr(1));

        /*
        if (!hasChildren && !child->isTerminal) {
        delete child;
        root->children[index] = NULL;
        }
        */

    }
    void deletion(string word){
        //just terminalnode = false;
        deleteWord(root, word);

    }
 };

int main(){
    Trie *t = new Trie();
    t->insertWord("ABCD");
    cout<<"present of not "<<t->search("ABCD")<<endl;
    return 0;
}

//time compl of insertion = O(L) same for searching