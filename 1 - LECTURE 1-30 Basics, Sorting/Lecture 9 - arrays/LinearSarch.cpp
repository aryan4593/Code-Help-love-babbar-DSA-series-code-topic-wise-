#include<iostream>
using namespace std;

bool search (int arr [],int n,int elemenet){
    for (int i =0;i<n;i++){
        if (arr[i]==elemenet){
            return true;
        }
    }
    return false;

}
int main (){
    int arr[10]={5,7,-6,8,3,22,56,45,61,1};
    // check 1
    cout<<search(arr,10,2);
}