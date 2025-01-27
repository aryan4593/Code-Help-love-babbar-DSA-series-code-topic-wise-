//using 2 stack;

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(mainStack.empty()){
            mainStack.push(val);
            minStack.push(val);
        }
        else{
            mainStack.push(val);
            if(val>=minStack.top()){
                minStack.push(minStack.top());
            }
            else minStack.push(val);
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
       return mainStack.top();
    }
    
    int getMin() {
       return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */