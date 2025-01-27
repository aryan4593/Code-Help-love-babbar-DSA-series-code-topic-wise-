#include <iostream>
#include <vector>
using namespace std;




#include <bits/stdc++.h>
void insertionSort(int n, vector<int> &arr){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j;
        for (j=i-1; j >= 0; j--){
            
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            
            else break;
        }
        arr[j + 1] = temp;
    }
}

int main(){
    vector<int> v1 {6, 2, 8, 4, 10};

    insertionSort(v1.size(), v1);

    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << endl;
    }
    return 0;
}