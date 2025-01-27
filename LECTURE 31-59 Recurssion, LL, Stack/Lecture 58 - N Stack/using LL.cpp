#include<iostream>
#include<stack>
using namespace std;



class node{
    public:
    int index;
    node* next;

    node(int x){
        index =x;
    }
};
class NStack
{
    int * arr; //original arary
    stack<int> emptyIndex;  //stack of empty index of array
    node** top; //top array which stores address of node index





public:
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new node*[N];
        for(int i =0;i<N;i++)
            top[i]=NULL;
        for(int i=0;i<S;i++){
            emptyIndex.push(i);
        }

    }
    bool push(int x, int m)
    {
        if(emptyIndex.empty()){
            return false;
        }
        int index = emptyIndex.top();
        arr[index]= x;
        node* newNode =new node(index);
        newNode->next=top[m-1];
        top[m-1]=newNode;
        emptyIndex.pop();
        return 1;
    }

    int pop(int m)
    {
        if(top[m-1]==NULL){
            return -1;
        }
        int ele = arr[top[m-1]->index];
        emptyIndex.push(top[m-1]->index);
        top[m-1]=top[m-1]->next;

        return ele;
    }
};
