#include<iostream>
using namespace std;

int main (){
    int row; cin>>row;
    int ** arr = new int* [row];  // row
    //this will create pointer and what is array? it is pointer pointing first location
    int col; cin>>col;
    for (int i = 0; i < row; i++)
    {
        arr[i] =new int [col];//col
    }
    
    //2d array of n*n size created;

    //taking input 

    for (int i =0;i<row;i++){

    for (int j =0;j<col;i++){
        cin>>arr[row][col];
    }

    }

    //releasing memory
    for (int i =0; i<row ;i++){
        delete [] arr[i];
    }

    delete arr;
    return 0;
}