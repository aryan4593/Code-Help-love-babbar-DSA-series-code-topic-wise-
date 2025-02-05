#include<iostream>
using namespace std;
#include<queue>

int main(){
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(30);
    q.push(7);
    cout<<"size of queue is "<<q.size()<<endl;
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;

    if(q.empty()){
        cout<<"queue is empty "<<endl;
    }
    else
        cout<<"queue is not empty "<<endl;
    
    cout<<"front of queue is "<<q.front();

    return 0;
}