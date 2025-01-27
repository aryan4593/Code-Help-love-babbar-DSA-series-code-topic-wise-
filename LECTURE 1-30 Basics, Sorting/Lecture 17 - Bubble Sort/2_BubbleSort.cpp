#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no two elements were swapped by the inner loop, the array is sorted
        if (!swapped) {
            break;
        }
    }
}



int  main (){
    vector <int>v1 {6 ,2, 8, 4, 10};

    bubbleSort(v1,v1.size());

    for (int i =0;i<v1.size();i++ ){
        cout<<v1[i]<<endl;
    }
}
