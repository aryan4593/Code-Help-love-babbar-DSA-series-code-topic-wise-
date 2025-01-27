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

void insertAtNode(node* &tail, int element,int val){
    if (tail==NULL){
        node* newNode = new node(val);
        tail=newNode;
        newNode->next=newNode;
    }
    //asumming that the element is present in list
      else{
        node* curr =tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* newNode = new node(val);
        newNode->next=curr->next;
        curr->next=newNode;
        tail = curr->next;
}

        
}

void print(node* &tail) {
    if (tail == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    
    cout << endl;
}

void deleteNode(node* tail,int ele){
    //empty
    if (tail==NULL){
        return;
    }
    else {
        //val is present asume
        node* prev=tail;
        node* curr=prev->next;

        while (curr->data != ele){
            prev = curr;
            curr= curr->next;
        }
        if (tail==curr){
            tail=curr->next;
        }
        prev->next = curr->next;
        curr->next=NULL;
        delete curr;
        
    }
    
}

int main (){
node*tail=NULL;
insertAtNode(tail,5,3);
print(tail);
insertAtNode(tail,3,5);
print(tail);
insertAtNode(tail,5,7);
// print(tail);
// insertAtNode(tail,3,5);
print(tail);

deleteNode(tail,3);
print(tail);


}







//there is no need of head node in circular linked list