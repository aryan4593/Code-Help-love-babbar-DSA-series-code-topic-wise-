#include<iostream>
using namespace std;
template<class t>
void printarray (t arr [],int n)
{
    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void swapalter (int arr [],int n){

 int i =0;
 while (i+1!=n-1){
    swap (arr[i],arr[i+1]);
    i=i+2;
 }
}

int main (){
  int  arr[6]={1,2,3,7,6,4};
  swapalter(arr,6);
  printarray(arr,6);
}