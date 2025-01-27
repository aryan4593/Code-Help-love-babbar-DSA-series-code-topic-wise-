#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int> arr, int n){
    int start =0, end = n-1;
    int mid = start + (end - start)/2;

    while (start<end){
        if(arr[mid]>=arr[0]){
            start = mid+1;
        } else if (arr[mid] < arr[end]) {
            end = mid;
        }
        
    }
return start;}

int BinarySearch(vector<int>& arr, int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int search(vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);

    if (k >= arr[0] && k <= arr[n - 1]) {
        return BinarySearch(arr, 0, pivot - 1, k);
    } else {
        return BinarySearch(arr, pivot, n - 1, k);
    }
}
