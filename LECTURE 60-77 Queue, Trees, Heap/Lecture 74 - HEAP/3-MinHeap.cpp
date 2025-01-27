#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h> 
void heapify (vector<int> &arr,int n, int i){
    int smallest = i ;
    int left = 2*i+1;
    int right = left +1;

    if(left< n and arr[left] < arr [smallest]){
        smallest = left;
    }
    if(right< n and arr[right] < arr [smallest]){
        smallest = right;
    }

    if(smallest != i ){
        swap (arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    for(int i = arr.size()/2; i>=0;i--){
        heapify(arr,arr.size(),i);
    }

    return arr;
}
