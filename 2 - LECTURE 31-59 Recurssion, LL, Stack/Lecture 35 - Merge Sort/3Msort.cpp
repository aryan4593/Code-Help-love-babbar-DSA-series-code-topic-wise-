#include<iostream>
using namespace std;
#include<vector>

void merge (vector<int> arr, int s, int e){
    int mid = e-(e-s)/2;
    int len1 = mid -s+1;
    int len2 = e -mid;

    vector<int> left(len1);
    vector <int> right (len2);

    int k =s;
    for (int i =0;i<len1;i++){
        left [i]= arr[k++];
    }

    for (int i =0;i<len2;i++){
        right[i]= arr[k++];
    }

    int index1=0;
    int index2=0;
    int index =0;
    while (index1<len1 && index2<len2){
        if (left[index1]<right [index2]){
            arr[index++]=left[index1++];
        }
        else
        arr[index++]=right[index2++];

    }

    while (index1<len1){
                    arr[index++]=left[index1++];

    }
   while (index2<len2){
            arr[index++]=right[index2++];

    }
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
}
int main (){

    return 0;
}