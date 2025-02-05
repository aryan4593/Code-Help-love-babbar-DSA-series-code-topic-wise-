#include <iostream>
using namespace std;
    


void Getarray (int arr [],int n)
{
    for (int i = 0;i<n;i++){
        cout<<"enter array of "<<i<<"th location"<<endl;
        cin>>arr[i];
    }
}
template<class t>
void printarray (t arr [],int n)
{
    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main (){

     int arr [15];
     cout<<sizeof(arr)/sizeof(int)<<endl;

// Getarray(arr,15) ;
// printarray(arr,15);
    char arr1[5]={'a','r','y','a','n'};
    printarray(arr1,5);
}