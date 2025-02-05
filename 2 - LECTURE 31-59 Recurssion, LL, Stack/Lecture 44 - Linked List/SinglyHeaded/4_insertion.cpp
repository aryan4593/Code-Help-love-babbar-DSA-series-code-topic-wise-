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
void insertAtHead (node* &head, int data){
    node *temp = new node (data);
    temp->next= head;
    head = temp;
}
void print (node* &head){
    
    node* temp= head;
    while(temp != NULL){
    cout<<temp->data<<" ";
    temp=temp->next;       
    }
    cout<<endl;

}

void insertAtPos ( node* &head, int pos, int data,node* &tail){
    if (pos==1){
        insertAtHead(head,data);
        return;
    }
    
    node* temp = head;
    int cnt =1;

    while (cnt<pos-1){
        temp = temp->next;
        cnt++; 
    }

//last position
    if (temp->next==NULL)
    {
        insertAtTail(tail,data);
    }
    

    node* Newnode = new node(data);
    Newnode->next=temp->next;
    temp->next = Newnode;
    
}

int main (){
    node* node1 = new node(5);
    node* head = node1;
    node* tail = node1;

    insertAtTail(tail,12);
    insertAtTail(tail,15);
    print(head);

    insertAtPos(head,3,22,tail);
    print(head);
}