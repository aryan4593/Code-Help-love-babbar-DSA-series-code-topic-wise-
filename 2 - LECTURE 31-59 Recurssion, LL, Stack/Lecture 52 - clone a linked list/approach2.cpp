// create a clone list usingi nxt pointer of original list
//map clone list with original list
// T=S=n

#include<iostream>
using namespace std;
#include<map>
// Definition for a Node.
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
        //step 1 clone lst

        Node* cloneHead = NULL;
        Node* cloneTail =NULL;
        Node* temp = head;

        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }

        //step 2 create map

        unordered_map<Node*,Node*> oldToNew;
        Node*originalNode = head;
        Node* cloneNode=cloneHead;
        while (originalNode!=NULL){
            oldToNew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;

        while(originalNode!=NULL){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }

        return cloneHead;
    }
};