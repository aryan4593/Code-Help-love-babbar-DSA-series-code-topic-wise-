#include<iostream>
using namespace std;

int getmax(int arr[],int n){

    int maxi = arr[0];

    for (int i =1;i<n;i++){
        // if (arr[i]>max){
        //     max = arr [i];
        // }
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int main (){

    int arr []={1,3,3,24321,41,413423,3};
    cout<<"Max value is "<<getmax(arr,sizeof(arr)/sizeof(int));
}