//without map here T=n and S=1

//s1 create a clone list
//clone nodes add between original list
//random Pointer
//revert changes of 2
#include<iostream>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
void insertAtTail(Node* &head,Node* &tail, int data){
        Node* newNode = new Node(data);
        if (head==NULL){
            head=newNode;
            tail=newNode;
        }

        else {
            tail->next= newNode;
            tail=newNode;
        }
    }


    Node* copyRandomList(Node* head) {

//step 1 = creat clone
        Node* cloneHead = NULL;
        Node* cloneTail =NULL;
        Node* temp = head;

        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
//step 2 = clone Nodes addd in between original list
        Node* orignalNode=head;
        Node* cloneNode= cloneHead;

        while(orignalNode!=NULL && cloneNode!=NULL){
            Node* next = orignalNode->next;
            orignalNode->next = cloneNode;
                orignalNode= next;

            Node* cloneNext = cloneNode->next;
            cloneNode->next = next;
                cloneNode=cloneNext;
        }

//step 3= copy random pointer
    temp=head;


    while(temp!=NULL){
        if(temp->next !=NULL){

            temp->next->random =temp->random ? temp->random->next:temp->random;
            // if(temp->random!=NULL)
            // temp->next->random = temp->random->next;

            // else 
            // temp->next->random = NULL;

            temp = temp->next->next;
        }}

        //revert changes
        orignalNode =head;
        cloneNode=cloneHead;

        while(orignalNode!=NULL && cloneNode!=NULL){
            orignalNode->next = cloneNode->next;
            orignalNode=orignalNode->next;
            if(orignalNode!=NULL)
            cloneNode->next=orignalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }

};

int main(){
    
}