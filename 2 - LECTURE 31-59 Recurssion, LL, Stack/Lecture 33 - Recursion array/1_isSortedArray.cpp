#include<iostream>
using namespace std;

bool isSorted (int *arr,int size){
    //base case
    if (size ==0) 
        return true;
    if (size ==1)
        return true;

    if (arr[0]>arr[1])
        return false;
    else {
        bool remainingPart = isSorted (arr+1,size-1);
        return remainingPart;
    }

    
    
}

int main (){
    int arr[5]={1,2,3,4,5};
    int size = 5;

    bool ans =isSorted(arr,size);
    cout<<ans;
    return 0;
}