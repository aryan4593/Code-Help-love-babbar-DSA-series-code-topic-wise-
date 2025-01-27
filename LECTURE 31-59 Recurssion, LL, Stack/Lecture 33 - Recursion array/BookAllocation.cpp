#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum (vector<int> &arr){
    int sum=0;
    for (int  i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int findPages(vector<int> &arr, int n, int m){
    sort(arr.begin(), arr.end());
    
}

int main(){
    
}