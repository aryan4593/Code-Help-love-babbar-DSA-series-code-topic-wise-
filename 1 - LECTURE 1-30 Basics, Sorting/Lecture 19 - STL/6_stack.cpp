//stack --> LIFO (plate example)

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> s;
    s.push("aryan ");
    s.push("Dnyaneshwar");
    s.push("Pungale");

    cout<<"top element "<<s.top()<<endl;

    s.pop();
    cout<<"top element "<<s.top()<<endl;
    cout<<"empty or not "<<s.empty()<<endl;
    return 0;
}