#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size, int key){
    int pos=0;
    int mid = size /2;
    while(arr[mid]!=key){
        if (arr[mid] == key)
        { pos = mid;}
        else if (arr[mid] > key){
            mid = mid/2;
        }
        else {
            mid = (mid+size)/2;
        }
        
    }
     

    return pos;
}

int main (){

    int arr[]= {1,2,4,6,7,8,9,87};

    cout<<BinarySearch(arr,7,87);
}
