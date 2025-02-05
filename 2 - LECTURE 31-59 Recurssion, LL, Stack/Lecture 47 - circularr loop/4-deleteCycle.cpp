#include<iostream>
using namespace std;    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };


Node *getIntersection (Node* head){
    Node* fast=head;
    Node* slow = head;
    
    while (fast!=slow || fast!=NULL||fast->next!=NULL){
        fast= fast->next->next;
        slow = slow->next;
    }
    if (fast ==NULL || fast->next==NULL){
        return NULL;
    }
    Node* intersection = fast;
    slow = head;

Node * prev;
    while (slow!=intersection){
        prev = intersection;
        slow->next;
        intersection->next;
    }
    

    return prev;
}
Node *removeLoop(Node *head)
{
    if (head == NULL){
        return head;
    }
    if (head->next==head){
        head->next = NULL;
        return;
    }

    getIntersection(head)->next=NULL;

    return head;
}
    
    

int main (){
    
}