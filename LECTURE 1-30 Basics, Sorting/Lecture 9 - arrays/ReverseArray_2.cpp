#include<iostream>
using namespace std;

template<class t>
void printarray (t arr [],int n)
{
    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void reverse(int arr[],int n){
   int start = 0,end =n-1;

   while(start<=end){
    swap(arr[start],arr[end]);
    start++;end--;
   }

}
int main (){
  int  arr[6]={1,2,3,7,6,4};
  reverse(arr,6);
  printarray(arr,6);
}