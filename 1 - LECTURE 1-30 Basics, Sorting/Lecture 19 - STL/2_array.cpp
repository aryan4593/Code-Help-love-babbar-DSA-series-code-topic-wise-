#include<iostream>
#include<array>
using namespace std;

int main (){
    int basic [3]= {1,2,3};

    array<int,4> a = {1,2,3,4};

    int size = a.size();
    cout<<"size is "<<size<<endl;

    for (int i =0; i<size ; i++){
        cout<<a[i]<<endl;
    }

    cout<<"Element at 2nd Index is "<<a.at(2)<<endl;
    cout<<"is array empty ?"<<a.empty()<<endl;

    cout<<"first element "<<a.front()<<endl;
    cout<<"last element "<<a.back()<<endl;

    
}