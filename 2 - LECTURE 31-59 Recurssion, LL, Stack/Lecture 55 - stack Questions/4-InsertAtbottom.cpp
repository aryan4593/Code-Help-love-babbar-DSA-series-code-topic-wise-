#in

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    if (myStack.empty()){
        myStack.push(x);
        return myStack;
    }

    int top = myStack.top();
    myStack.pop();
    myStack=pushAtBottom( myStack, x);
    myStack.push(top);

    return myStack;

}
