#include <vector>
#include<iostream>
using namespace std;
#include <algorithm> // For std::swap

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i =0; i<n-1;i++){
        for (int j = i+1;j<n; j++){
            if (arr[i]>arr[j])
                swap(arr[i],arr[j]);
                cout<<"swapped "<<arr[j]<<" and "<<arr[i]<<endl;
        }
    }
}

int main (){
    vector <int>v1 = {12,4,1,4,14,10};

    selectionSort(v1);

    for (int i =0;i<6;i++){
        cout<<v1[i]<<endl;
    }
}

