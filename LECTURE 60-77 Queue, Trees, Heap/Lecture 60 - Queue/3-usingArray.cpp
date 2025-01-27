#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Queue {
  int size;
  int *arr;
  int qfront, rear;

public:
  Queue() {
      size=1000001;
      arr = new int[size];
      qfront=0;
      rear =0;
  }

  bool isEmpty() {
      if(rear == qfront){
          return true;
      }
      return false;
  }

  void enqueue(int data) {
      if(rear == size){
          return;
        //   cout<<"queue is full "<<endl;
      }

      else {
          arr[rear]=data;
          rear++;
      }
  }


  int dequeue() {
      if(qfront==rear){
          return -1;
      }
      
      else{
          int ans = arr[qfront];
          arr[qfront ]==-1;
          qfront++;
          if(qfront ==rear){
              qfront=0;
              rear =0;
          }
     return ans;
      }
  }

  int front() {
      if(qfront==rear){
          return -1;
      }
      else return arr[qfront];
  }
};


int main(){
    cout<<"main function";
return 10;
}