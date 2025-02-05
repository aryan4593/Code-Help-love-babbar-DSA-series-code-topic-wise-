#include<iostream>
using namespace std;


bool isPresent (int *arr, int size,int ele){

    if (size ==0){
        return false;
    }
    if (arr[0] == ele ){
        return true;
    }
    else 
     {bool ans =isPresent(arr+1,size-1,ele);
    return ans;}
}
    


int main (){
    int arr[5]={1,2,3,4,5};
    int size = 5;

    cout<<isPresent(arr,5,6);
    return 0;
}