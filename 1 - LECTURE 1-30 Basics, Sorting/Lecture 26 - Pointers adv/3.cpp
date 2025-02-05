#include<iostream>
using namespace std;

int main (){

    int arr[10];
    //error 
    // arr = arr+1;
    int *ptr=arr;
    cout<< ptr <<endl;
    ptr = ptr+1;
    cout<< ptr <<endl;
}