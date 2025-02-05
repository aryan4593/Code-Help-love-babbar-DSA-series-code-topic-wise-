#include<iostream>
#include<vector>
using namespace std;


void reverseArray(vector<int> &arr , int m) {

    int s=m+1,e = arr.size()-1,temp;
   while(s<=e){
        temp = arr[e];
        arr[e]=arr[s];
        arr[s]=temp;
        s++;e--;

    
    }
}

int main (){
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    reverseArray(v1,3);
    for (int i = 0; i < 6; i++)
    {
        cout<<v1[i];
    }
    
}