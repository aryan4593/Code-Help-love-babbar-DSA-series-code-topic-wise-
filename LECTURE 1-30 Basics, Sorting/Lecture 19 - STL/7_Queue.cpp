#include<iostream>
#include <queue>
using namespace std;

// Queue --> FIFO       O(1)

int main (){
    queue<string> q;
    q.push("aryan ");
    q.push("Dnyaneshwar");
    q.push("Pungale");

    cout<<"first element "<<q.front()<<endl;
    q.pop();
    cout<<"first element "<<q.front()<<endl;

}