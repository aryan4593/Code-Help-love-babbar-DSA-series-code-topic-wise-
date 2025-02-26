#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
    int start =0, end = n-1;
    int mid = start + (end - start)/2;

    while (start<end){
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }
        else if(arr[mid]<arr[end]){
            end = mid;
        }
        return start;
    }
}

int main (){
    int arr[5]= {8,10,17,1,3};

    cout<<"pivot is "<<getPivot(arr,5)<<endl;
}