#include<iostream>
#include<queue>
using  namespace std;
int main(){
    cout<<"using priority queue here"<<endl;
    priority_queue<int> pq; // it is max heap
    priority_queue <long long , vector<long long> , greater <long long> >pq;  //min heap
    pq.push(55);
    pq.push(53);
    pq.push(30);
    pq.push(87);

    cout<<pq.top()<<endl;

}