#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        for(int i =0;i<s.size();i++){
            st.push(s[i]);
        }
         vector<char> s1;
        while(!st.empty()){
            char ch = st.top();
            s1.push_back(ch);
            st.pop();
        }
        s=s1;

    }
};
int main (){

}


//t(c)=O(n)=S(s)