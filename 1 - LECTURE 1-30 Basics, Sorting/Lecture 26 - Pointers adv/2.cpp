#include<iostream>
using namespace std;

int main (){
    int arr[10]={1,5,7,9,3,5,5,4};
    cout<<"address of first memory block is "<<arr<<endl;       //name stores address of first block
    cout<<"address of first memory block is "<<&arr[0]<<endl;
    cout<<"value at 0th index "<<*arr<<endl;      // dereference operator for first blck
    cout<<"value at 1th index "<<*(arr+1)<<endl;      // dereference operator for first blck
    cout<<"it will give arr[0]+1 = "<<*arr+1<<endl;      // dereference operator for first blck

    int i =3;
    cout<<i[arr]<<endl; // new way of writing
    return 0;
}