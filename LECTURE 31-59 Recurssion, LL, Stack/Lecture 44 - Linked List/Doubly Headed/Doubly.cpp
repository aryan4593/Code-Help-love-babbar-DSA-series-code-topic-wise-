#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node (){
        int val = this->data ;

        if (next!=NULL){
            cout<<"entered if"<<endl;
            delete next;
            next=NULL;
        }
    }
};
void print(Node *&head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head){
    Node *temp = head;
    int length = 0;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
        length++;
    }
    cout << endl;
    return length;
}

void insertAthead(Node *&head, int ele){
        if (head == NULL){
        Node* temp = new Node (ele);
        head=temp;
        return;
         }
    Node *newNode = new Node(ele);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&tail, int data){

    if (tail == NULL){
        Node* temp = new Node (data);
        tail=temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, int pos, int data, Node *&tail){
    Node *temp = head;
    if (pos == 1){
        Node *newNode = new Node(data);
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
        return;
    }

    else{
        Node *newNode = new Node(data);
        Node *temp = head;
        Node *previ = NULL;
        int cnt = 1;
        while (cnt < pos){
            previ = temp;
            temp = temp->next;
            cnt++;
        }
        if (temp == NULL || temp->next == NULL){
            insertAtTail(tail, data);
            return;
        }
        previ->next = newNode;
        newNode->prev = previ;
        newNode->next = temp;
        temp->prev = newNode;
    }
}

void deleteNode(int pos, Node* &head,Node* &tail){    
    Node *temp = head;
    // start Node
    if (pos ==1){
        temp->next->prev=NULL;
        head=head->next;

        temp->next=NULL;
        //free memory
        delete temp;
    }

    else{
        Node* current = head;
        Node*prev = NULL;
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
    current->next=NULL;
    current->prev=NULL;
    current->next = NULL;
    delete current;
}
}
int main() {

    Node *Node1 = new Node(10);
    Node *head = Node1;
    Node *tail = Node1;
    print(head);
    insertAthead(head, 11);
    print(head);
    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, 4, 88, tail);
    print(head);
    deleteNode(1,head,tail);
    print(head);
    deleteNode(3,head,tail);
    print (head);
}
