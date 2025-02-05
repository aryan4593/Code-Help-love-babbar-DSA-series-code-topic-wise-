#include<iostream>
using namespace std;


void print (int arr[], int n, int start =0){ //this is default argument, if no arg is passed of start, 0 will be there
    for (int i = start; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main (){
    int arr[5]={1,4,7,8,9};
    print(arr,5,2);cout<<"endl";
    print(arr,3);

    //priority of default argument - right to left means you can't do (int arr[],int n=0,int start)
    return 0;
}