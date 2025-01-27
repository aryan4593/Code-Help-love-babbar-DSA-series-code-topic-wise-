#include<iostream>
using namespace std;

int main (){
    // int *p =0;
    // cout<<*p;//segmentation fault
    int i =5;
    int *p =0;
    p =&i;
    cout<<p<<" "<<*p;
    (*p)++;
    cout<<"\nincremented i is "<<i;
}