#include <iostream>
using namespace std;
#include <string>
#include <stack>
class Solution{
public:
    int minAddToMakeValid(string s){
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(' && (!st.empty() && st.top() == ')')){
                st.push(s[i]);
                count++;
            }

            else if (s[i] == '(' && (st.empty() || st.top() == '(')){
                st.push(s[i]);
                count++;
            }

            else if (s[i] == ')' && (!st.empty() && st.top() == '(')){
                st.pop();
                count--;
            }
            else if (s[i] == ')' && (st.empty() || st.top() == ')')){
                st.push(s[i]);
                count++;
            }
        }
        return count;
    }
};