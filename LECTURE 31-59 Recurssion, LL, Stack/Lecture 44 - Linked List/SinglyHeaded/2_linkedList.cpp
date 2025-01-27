#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void insertAtHead (Node* &head,int d){
    //create new node

    Node*temp = new Node(d);
    temp->next=head;
    head = temp;
}

void print (Node* &head){
    
    Node* temp= head;
    while(temp != NULL){
    cout<<temp->data<<" ";
    temp=temp->next;       
    }
    cout<<endl;

}
int main (){
    Node* Node1 = new Node(5);
    // cout<<Node1->data<<endl;
    // cout<<Node1->next<<endl;
    Node* head = Node1;
    

    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);
}


//ulta implementation