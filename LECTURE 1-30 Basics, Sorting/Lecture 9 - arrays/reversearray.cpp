#include<iostream>
using namespace std;

void reverse(int arr[],int n){
    for (int i = 0; i<=n/2;i++){
        int temp;
        temp = arr[i];
        arr[i] = arr[ n];
        arr[n]= temp;
        n--;
    }

}


int main (){

    int arr []={1,3,4,24,21,41,34,23,3};
    reverse(arr,9);
        for (int i = 0; i<9;i++){
        cout<<arr[i]<<" ";
    }

   
}