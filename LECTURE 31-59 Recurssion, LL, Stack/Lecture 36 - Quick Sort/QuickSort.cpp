#include<iostream>
#include<algorithm>
using namespace std;

int partition (int *arr, int s, int e){
    //logic- count all elements in array which are less that pivot
    //swap s,s+count
    int pivot = arr[s];
    int count =0;
    for (int i = s+1; i < e; i++)
    {
        if (arr[i]<=pivot)
            count ++;
    }
    int pivotIndex = count +s;
    swap(arr[pivotIndex],arr[s]);

    //left and right wala part
    int i =s,j=e;
    while (i<pivotIndex&& j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        if (i<pivotIndex&& j>pivotIndex){
            swap (arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
    
}

void quickSort (int *arr,int s, int e){
    if (s>=e){
        return;
    }
    int p = partition (arr,s,e);    //index

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
    //rec
}

int main (){
    int arr [5]={5,2,9,6,12};
    quickSort(arr,0,4);
    
    for (int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}