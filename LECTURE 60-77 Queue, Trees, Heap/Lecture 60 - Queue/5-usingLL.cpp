#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int data){
        this->val=data;
        this->next=nullptr;
    }
};

class Queue{
private:
    node* front;
    node* rear;
public:
    Queue(){
        front =NULL;
        rear=NULL;
    }

    void enQueue(int data){
        node* newNode = new node(data);
        if(isEmpty()){
            front=newNode;
            rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }

    }
    void deQueue(){
        if(isEmpty()){
            return;
        }
        node* temp = front;
        front=front->next;
        temp->next=NULL;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return;
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    int Front(){
        if(!isEmpty()){
            return this->front->val;
        }
        else return -1;
    }
    int Rear(){
        if(!isEmpty()){
            return this->rear->val;
        }
        else return -1;
    }

};

int main(){

    return 0;
}