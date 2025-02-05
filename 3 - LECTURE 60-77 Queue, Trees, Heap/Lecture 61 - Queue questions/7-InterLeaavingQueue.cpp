#include<iostream>
using namespace std;
#include<queue>

void interLeaveQueue(queue < int > & q) {
    int i=0;
    queue<int> newQ;
    while(i<q.size()){
        newQ.push(q.front());
        q.pop();

        i++;
    }

    while(!newQ.empty()){
        q.push(newQ.front());
        newQ.pop();
        q.push(q.front());
        q.pop();
    }

}