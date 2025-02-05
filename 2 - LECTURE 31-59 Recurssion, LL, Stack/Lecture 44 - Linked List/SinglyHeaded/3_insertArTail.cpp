#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;

    node (int data){
        this->data= data;
        next=NULL;
    }
};

void insertAtTail (node* &tail,int n){
    node *temp = new node(n);
    (*tail).next =temp;
    tail= temp;
}
void print (node* tail){
    node *dummy = tail;
    while (dummy!=NULL){
        cout<<dummy->data<<" ";
        dummy = dummy->next;
    }
    cout<<endl;
}
int main (){
    node* node1 = new node(5);
    node* head = node1;
    node* tail = node1;

    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
}