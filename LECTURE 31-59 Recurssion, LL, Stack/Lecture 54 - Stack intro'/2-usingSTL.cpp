#include<iostream>
#include<stack>
using namespace std;

int main (){
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout<<"top element is "<<s.top()<<endl;
    s.pop();
    cout<<"top element is "<<s.top()<<endl;

    if(s.empty()){
        cout<<"stack is empty \n";
    }
    else 
        cout<<"stack is not empty \n";

    cout<<"size of stack is "<<s.size();

    return 0;
}