#include <vector>
#include<iostream>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) {
            return false; // If any book has more pages than mid, it's not possible
        }
        
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
    
        else {
            studentCount++;
            pageSum = arr[i];
            if(studentCount > m) {
                return false;
            }
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (n < m) {
        return -1; // Not enough books for each student
    }

    int s = 0;
    int e = 0;
    
    // Calculate the sum of all pages to set upper bound of binary search
    for(int i = 0; i < n; i++) {
        e += arr[i];
    }

    int ans = -1;

    // Binary search
    while(s <= e) {
        int mid = s + (e - s) / 2;
        
        // If it's possible to allocate pages with a maximum of 'mid'
        if(isPossible(arr, n, m, mid)) {
            ans = mid; // Update ans with current mid
            e = mid - 1; // Search in the left half for a smaller mid
            cout<<ans<<endl;
        }
        else {
            s = mid + 1; // Search in the right half for a larger mid
        }
    }
    return ans;
}

int main (){
    vector<int> v = {10 ,20, 30, 40};
    cout<<findPages(v,4,2);

}