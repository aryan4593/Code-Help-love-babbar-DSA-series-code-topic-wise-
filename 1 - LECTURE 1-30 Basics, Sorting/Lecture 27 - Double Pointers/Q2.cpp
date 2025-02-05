#include<iostream>
using namespace std;

int main (){
    int first =6;
    int *p = &first;
    int *q= p;      //q pointer stored p means it stored directly value of address of first
    // so q is pointing first
    (*q)++;
    cout<<first<<endl;

    return 0;
}