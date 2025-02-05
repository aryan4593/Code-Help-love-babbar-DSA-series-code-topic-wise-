#include<iostream>
using namespace std;
#include<map>
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node *removeDuplicates(Node *head)
{
    map<int , bool> visited;
    Node* temp= head;
    do {
    visited[temp->data]=true;
    if (visited[temp->next->data]==true){
        Node* toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }
    else {
        temp =temp->next;
    }
    }while (temp!=NULL);

}



// map solution --> Time comp =O(N)
// space comp O(N)