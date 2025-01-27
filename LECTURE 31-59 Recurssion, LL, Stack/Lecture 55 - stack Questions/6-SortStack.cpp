#include<iostream>
using namespace std;
#include<stack>
void insertInSortedWay(stack<int> &stack,int top){
	if (stack.empty()){
		stack.push(top);
        return;
	}

	if(stack.top()<=top){
		stack.push(top);
        return;
	}

	int ele= stack.top();
	stack.pop();
	insertInSortedWay(stack,top);
	stack.push(ele);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	insertInSortedWay(stack,top);
return;
}