#include<iostream>
#include<string>

class Solution {
public:
    bool isPalindrome(string s) {
        bool isPal = true;
        int n =s.length();


        for (int i =0;i<n;i++){
        s[i]=tolower(s[i]);            
        }
        string s2;
        int m =0;
        for (int i =0;i<n;i++){
        if (97<=s[i]<=123){
            s2[m]=s[i];
            m++;
        }            
        } 
    int st =0, e=s2.length()-1;       
        while(st<e){
            if (s2[st]!=s2[e]){
                isPal = false;
            }
            st++;e--;
        }
        return isPal;
        
    }
};

int main (){
    
}