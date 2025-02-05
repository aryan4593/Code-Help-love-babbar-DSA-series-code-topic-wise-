#include<iostream>
#include<stack>
using namespace std;
bool matches(char b, char a){
    if(a=='}' && b=='{')
        return true;
    if(a==']' && b=='[')
        return true;
    if(a==')' && b=='(')
        return true;

    return false;
}

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(int i =0;i<s.length();i++){
       char ch = s[i];
       
       if(ch=='[' or ch=='{' or ch=='('){
           st.push(ch);
       }

       else{
           if(!st.empty()){

               char top = st.top();
               if(matches(top,ch)){
                   st.pop();
               }
               else return false;
           }

           else return false;
       }
    }

    return st.empty();
}
int main(){
    
}