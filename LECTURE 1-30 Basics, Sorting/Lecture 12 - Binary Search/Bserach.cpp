#include<iostream>
using namespace std; 

bool Bsearch (int arr[], int n, int ele){
    int s =0, e =n;
    while (e>=s){
    int mid = s+e/2;
    if (arr[mid]==ele)
    return true;

    else if (arr[mid]>ele){
        e= mid;
    }
    else
    s= mid;}
    return false;
}

int main (){

    int arr[]={1,2,3,4,5,6};
    cout<<"hello"<<endl;
    if (Bsearch(arr,5,7)==true)
    cout<<"Yes";
    if (Bsearch(arr,5,7)==false)
    cout<<"no";
    
}