#include<iostream>
#include<stack>
using namespace std;



class node{
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
        arr = new int[N];
        top = new node*[S];

    }
    bool push(int x, int m)
    {

    }

    int pop(int m)
    {
        //underflow
        

    }
};
