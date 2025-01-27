#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

};
class stack{
    public:
    Node* top;

    stack(){
        top =NULL;
    }

    void push (int val){

        //this is insertAtHead operation
        Node* newNode = new Node();
        newNode->data=val;
        newNode->next=top;
        top = newNode;

    }

    void pop(){
        if(!isEmpty()){
        Node*temp=top;
        top =top->next;
        delete temp;
        }
        else 
        cout<<"stack is empty"<<endl;

    }

    bool isEmpty(){
        if(this->top==NULL){
            return true;
        }
        else return false;
    }

    int peek(){
        if(!isEmpty()){
            return top->data;
        }
        else return -1;
    }



    ~stack() {
        while (!isEmpty()) {
            pop();  // Free all nodes
        }
    }

};