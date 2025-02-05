// GIVEN A HEAP
// swap root  with last element
// size--
// hepaify root
// repeat

#include <iostream>
using namespace std;

void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = left + 1;

    if (left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if (i != largest){
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int size){

    while (size > 1){
        
        swap( arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    cout << "Hello, world " << endl;
    int arr [6]= {-1,70,60,50,55,45};
    int n = 5;

    for(int i = n/2; i>0;i--){
        heapify(arr,n,i);
    }

    heapSort(arr,n); 
    for (int i = 1; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}