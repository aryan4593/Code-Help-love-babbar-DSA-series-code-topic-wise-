//without data replacement

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
void insertAtTail (Node* &tail, Node* & temp){
    tail->next=temp;
    tail=temp;

}

Node* sortList(Node *head){
    Node* zero= new Node(-1);
    Node* zeroTail = zero;
    Node* one=new Node(-1);
    Node* oneTail = one;
    Node* two=new Node(-1);
    Node* twoTail = two;

    Node* temp =head;

    while (temp!=NULL){
        if (temp->data==0){
            insertAtTail(zeroTail, temp);
            
        }
        if (temp->data==1){
            insertAtTail(oneTail, temp);

        }
         if (temp->data==2){
             insertAtTail(twoTail, temp);

        }

        temp=temp->next;
    }

    // merge
    if (one->next!=NULL){
        zeroTail->next = one->next;
    }
    else {
        ///ont list is empty
        zeroTail->next = two->next;
    }

    oneTail->next= two->next;
    twoTail->next=NULL;

    return zero->next;





}
int main (){

    return 0;
}


//Tc =O(n)
//sc= O(1)
