#include<iostream>
using namespace std;

void merge (int *arr,int s, int e){
    int mid = s +(e-s)/2;

    int len1 = mid -s +1;
    int len2 = e - mid;

    int arr1[len1];
    int arr2[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }
    
    
    k = mid +1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

//merge
int index1=0,index2=0;
int mainArrayIndex = s;

while (index1<len1 && index2<len2){

    if (arr1[index1]<arr2[index2]){
        arr[mainArrayIndex++] = arr1[index1++]; 
    }
    else
        arr[mainArrayIndex++] = arr2[index2++]; 

}

while (index1<len1){
        arr[mainArrayIndex++] = arr1[index1++]; 
    
}

while (index2<len2){
    arr[mainArrayIndex++] = arr2[index2++]; 

}
    

}

void mergeSort(int *arr, int s, int e){
    if (s>=e) 
        return;

    int mid = s+(e-s)/2;
    // left Part
     mergeSort(arr,s,mid);

    // right part
     mergeSort(arr,mid+1,e);

     merge(arr,s,e);
    
}

int main (){
    int arr [5]={5,2,9,6,12};
    
    mergeSort (arr,0,5);
    
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}