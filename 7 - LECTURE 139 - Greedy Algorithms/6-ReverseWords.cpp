#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string &s) {
        string ans = "";
        string temp = "";
        
        for(int i=s.size() - 1; i>=0 ; i--){
            char ch = s[i];
            
            if(ch == ' '){
                if(temp == "") continue;
                reverse(temp.begin(), temp.end());
                
                ans+=temp;
                ans.push_back(' ');
                
                temp = "";
            }
            
            else{
                temp.push_back(ch);
            }
        }
        
        if(s[0] != ' '){
            //means last charector is not processed
            reverse(temp.begin(), temp.end());
            ans += temp + ' ';
        }
        
        ans.pop_back(); // last space
        
        return ans;
    }
};

int main() {

}



/*
 // leetcode 151 : 
class Solution {
public:
    string reverseWords(string s) {
         reverse (s.begin(), s.end());
         stringstream sstr(s);
         string word;
         string ans;
         while(sstr >> word){
            if(word != " "){
                reverse(word.begin(), word.end());
                ans += word + ' ';
            }
         } 

         ans.pop_back(); // last space
         return ans ;
    }
};
*/