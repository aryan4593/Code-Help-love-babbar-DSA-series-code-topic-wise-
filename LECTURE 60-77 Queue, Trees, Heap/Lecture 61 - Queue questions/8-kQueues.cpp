#include<iostream>


#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
class NQueue{
public:

    int * arr;
    int *front;
    int * rear;
    int* next;
    int freespot;
    NQueue(int n, int s){
        arr = new int[s];

        next = new int[s];
        for(int i =0;i<s;i++){
            next[i]=i+1;
        }
        next[s-1]=-1;
        freespot=0;

        front = new int[n];
        rear = new int[n];

        for (int i = 0; i < n; i++){
            front[i]=rear[i]=-1;
        }
        
    }

    bool enqueue(int x, int m){
        if(freespot==-1){
            return false;
        }
        int index=freespot;
        freespot = next[freespot];
        if(front[m-1]==-1){
            //first element of m-1th queue
            front[m-1]=index;
        }
        else{
            //not first element
            next[rear[m-1]]=index;
            arr[index]=x;            
        }
            next[index]=-1;
            rear[m-1]=index;
            arr[index]=x;
            return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //underflow
        if(front[m-1]==-1){
            return -1;
        }
        //find index 
        int index = front[m-1];
        //delete element
        int ans = arr[index];
        arr[index]=-1;

        //update front
        front[m-1]=next[index];
        ///link and updatew freespot
        next[index]=freespot;
        freespot =index;

        return ans;
    }
};