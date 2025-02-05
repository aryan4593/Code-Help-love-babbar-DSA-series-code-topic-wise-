#include<iostream>
#include<vector>

using namespace std;

int main (){
    vector<int> v;
    
    v.push_back(3);
    cout<<"capacity "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"capacity "<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"capacity "<<v.capacity()<<endl;      //it doubles the capacity
    cout<<"size "<<v.size()<<endl;      

    cout<<"front "<<v.front()<<endl;
    cout<<"back "<<v.back()<<endl;
    cout<<endl<<endl<<"before pop \n";
    for (int i : v){
        cout<<i<<" ";
    }

    v.pop_back();
        cout<<endl<<endl<<"after pop \n";
    for (int i : v){
        cout<<i<<" ";
    }

    cout<<endl<<"Before clear size is "<<v.size()<<" capacity is "<<v.capacity()<<endl;
    v.clear();
    cout<<"Before clear size is "<<v.size()<<" capacity is "<<v.capacity()<<endl;

    vector<int > a (5,1);
    cout<<"printing a "<<endl;
        for (int i : a){
        cout<<i<<" ";
    }

    vector<int> last (a); // will copy elements of a in last vector
    
}