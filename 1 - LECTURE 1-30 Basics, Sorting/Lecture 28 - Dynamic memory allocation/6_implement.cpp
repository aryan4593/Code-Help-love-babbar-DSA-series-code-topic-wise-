#include<iostream>
using namespace std;

int getSum (int *arr, int n){
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
    
}
int main (){
    int n;
    cin>>n;
    int* arr = new int [n];     //this is correct way to take size of array from user

    for(int i =0;i<n; i++){
        cin>>arr[i];
    }
    cout<<"sum is "<<getSum(arr,n);
    return 0;
}