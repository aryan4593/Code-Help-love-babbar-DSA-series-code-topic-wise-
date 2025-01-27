#include<iostream>
#include<stack>
using namespace std;

#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i =0;i<s.length();i++){
        if(s[i]=='(' ||s[i]=='+' ||
            s[i]=='-' ||s[i]=='*' ||s[i]=='/'){
                st.push(s[i]);
            }

        else {
            if(s[i]==')'){
                if(st.top()=='('){
                    return true;
                }

                else{
                    while(st.top()!='(' && !st.empty()){
                        st.pop();
                    } 
                    if(st.top()=='(')
                        st.pop();
                }
            }
        }
    }

    return false;
}


