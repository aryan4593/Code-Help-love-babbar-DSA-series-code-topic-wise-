#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
//constructor
    node (int data){
        this->data= data;
        next=NULL;
    }

//destructor
 ~node (){
    int value = this->data;
    if (this->next!=NULL){
        delete next;
        this->next = NULL;
    }
    cout<<"memory freed for node with dATA "<<value<<endl;

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

void deleteNode(int pos, node* &head,node* &tail){    
    node *temp = head;
    // start node
    if (pos ==1){
        head=head->next;
        //free memory
        temp->next=NULL;
        delete temp;
    }

    else{
        node* current = head;
        node*prev = NULL;
        int cnt =1;
        while(cnt<pos){
            prev = current;
            current=current->next;
            cnt++;
        }
    if (current->next==NULL){
        tail =prev;
    }
    prev->next=current->next;
    current->next = NULL;
    
    delete current;
}
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

    deleteNode(2,head,tail);
    print(head);
}