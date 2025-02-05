#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check if left child exists and is greater than the current largest
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Check if right child exists and is greater than the current largest
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not the root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

public:
    vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
        // Step 1: Add all elements from heap b to heap a
        for (int i = 0; i < m; i++) {
            a.push_back(b[i]);
        }

        // Step 2: Heapify the merged array (now of size n + m)
        int size = n + m;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(a, size, i);
        }

        return a;
    }
};