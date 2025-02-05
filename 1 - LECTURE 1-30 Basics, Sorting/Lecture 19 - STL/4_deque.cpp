// doubly headed queue

#include<iostream>
#include<deque>
using namespace std;

int main (){
    deque<int> d;

    d.push_back(1);
    d.push_back(4);
    d.push_front(2);
    for (int i :d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.pop_back();
        for (int i :d){
        cout<<i<<" ";
    }

    cout<<"first index "<<d.at(1)<<endl;

    cout<<d.front()<<" "<<d.back()<<endl;
    cout<<"empty "<<d.empty()<<endl;

    cout<<"before erase size is "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<"after erase size is "<<d.size()<<endl;






}
