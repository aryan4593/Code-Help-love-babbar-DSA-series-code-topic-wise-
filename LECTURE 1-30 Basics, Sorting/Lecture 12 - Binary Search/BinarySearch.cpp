#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 8, 9, 87};

    cout << BinarySearch(arr, 8, 87); 
    return 0;
}
