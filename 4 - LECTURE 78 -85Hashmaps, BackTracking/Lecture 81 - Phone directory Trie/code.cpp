#include<iostream>
#include<vector>
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

    void printSuggestion(TrieNode* curr , vector<string> &temp , string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch = 'a' ;  ch<='z'; ch++){
            TrieNode* next = curr->children[ch - 'a'];

            if(next){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string queryStr){
        vector<vector<string>> ans;
        TrieNode* prev = head;
        string prefix ="";

        for(int i=0;i<queryStr.length();i++){
            char lastChar = queryStr[i];
            prefix.push_back(lastChar);

            //check for lastCh
            int index = lastChar - 'a';

            TrieNode* curr = prev->children[index];

            if(!curr){
                break;
            }
            vector<string> temp;
             printSuggestion(curr, temp, prefix);

            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return ans;

    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //insert all contact in trie
    Trie t;
    for(int i = 0; i<contactList.size();i++){
        string str = contactList[i];
        t.insert(str);
    }
    return t.getSuggestions(queryStr);
}

int main() {
    vector<string> contactList = {"alice", "aryan","arya","arnav", "bob", "carol", "dave"
    , "eve", "frank", "grace", "heidi", "ivan", "judy", "mallory", "oscar", 
    "peggy", "trent", "victor", "walter", "xavier", "yvonne", "zara"};

    string queryStr;
    cout<<"Enter your query string "<<endl;
    cin>>queryStr;
    vector<vector<string>> suggestions = phoneDirectory(contactList, queryStr);

    for (int i = 0; i < suggestions.size(); i++) {
        cout << "Suggestions for \"" << queryStr.substr(0, i + 1) << "\":" << endl;
        for (const string& suggestion : suggestions[i]) {
            cout << suggestion << endl;
        }
        cout << endl;
    }

    return 0;
}

// T.C = word length = m  , contact list = n ;
//S.C = m*n;
// t.c = O(n*m^2)



