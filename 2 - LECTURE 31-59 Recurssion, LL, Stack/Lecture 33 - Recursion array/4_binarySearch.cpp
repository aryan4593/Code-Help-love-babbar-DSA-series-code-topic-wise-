#include<iostream>
using namespace std;


bool binarySearch (int *arr, int s, int e,int ele){
     if (s>e)
        return false;
     int mid = s+(e-s)/2;
    if (arr[mid ]==ele)
        return true;
   
    if (arr[mid]<ele)
        return (arr,mid+1,e,ele);
    
    if (arr[mid]>ele)
       return binarySearch(arr,s,mid-1,ele);   
}

int main (){
    int arr[5]={1,2,3,4,5};
    int size = 5;
    int key=9;
    cout<<binarySearch(arr,0,size-1,key);
    return 0;
}