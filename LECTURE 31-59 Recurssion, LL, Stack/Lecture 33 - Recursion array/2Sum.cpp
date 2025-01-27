#include<iostream>
using namespace std;

int sum (int *arr, int size){
    if(size ==0){
        return 0;
    }
    if (size ==1){
        return arr[size];
    }

    int add =0;
    // cout<<"arr[0] is "<<arr[0]<<endl;
    add= arr[0]+sum(arr+1,size-1);

    // cout<<"currently sum is "<<add<<endl;

    return add;
    
}

int main (){
    int arr[5]={1,2,3,4,5};
    int size = 5;
    cout<<sum(arr,size);
    return 0;
}