#include<iostream>
using namespace std; 

int main (){
    int num =5;
    cout<<num<<endl;

    //address of operator - &.
    
    cout<<"address of num is "<<&num;  //it is hexadecimal for
    //Pointer will store this address
    int *ptr =&num;     //declaring pointer
    cout<<endl<<"value stored in pointer is " <<ptr;
    cout<<endl<<"value is " <<*ptr;
    cout<<"\nsize of pointer is "<<sizeof(ptr)<<endl;
    int n = sizeof(ptr);        //size 8 bytes
    cout<<n;

    return 0;
}