#include<iostream>
using namespace std;

int main (){
    int arr[]={11,21,31,41};
    int *ptr = arr++;   //as arr is constant which contain address of arr[0], it can't be incremented 

    cout<<*ptr;
    return 0;
}