#include<iostream>
using namespace std;
#include<stack>

void pushAtBottom(stack<int>& myStack, int x) 
{
    if (myStack.empty()){
        myStack.push(x);
        return ;
    }

    int top = myStack.top();
    myStack.pop();
    pushAtBottom( myStack, x);
    myStack.push(top);

    return ;

}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){

        return;
    }

    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    pushAtBottom(stack,  top);


}