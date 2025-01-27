#include<iostream>
using namespace std;

class MyCircularDeque {
    int *arr;
    int front,rear;
    int size;

public:
    MyCircularDeque(int k) {
        size =k;
        arr = new int [k];
        front=rear=-1;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front=rear=0;
            arr[front] =value;
            return true;
        }


        if(front==0){
            front =size -1;
        }
        else front--;

        arr[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front =rear=0;
            arr[rear]=value;
        }
        else if(rear==size-1){
            rear=0;
        }
        else rear++;
        arr[rear]=value;

        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            arr[front]=-1;
            front =rear=-1;
            return true;
        }
        arr[front]=-1;
        
        if(front==size-1){
            front =0;
        }
        else front++;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        if(rear==front){
            arr[rear]=-1;
            front=rear=-1;
            return true;
        }
        arr[rear]=-1;
        if(rear==0){
            rear =size-1;
        }
        else rear--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        else return arr[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        else return false;
    }
    
    bool isFull() {

        if(size==2){
           if(front==rear){
            return false;
           }
        }
        if((front==0 && rear==size-1 ) || rear == (front-1)%(size-1)){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);a
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
