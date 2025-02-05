//bruteforce

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
    vector<int> bruteForce;
    
    // Generate all subarray sums
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = i; j < arr.size(); j++) {
            sum += arr[j];
            bruteForce.push_back(sum); // Store each subarray sum
        }
    }

    // Sort the bruteForce array to get the largest sums
    sort(bruteForce.begin(), bruteForce.end());
    
    // Return the k-th largest element
    return bruteForce[bruteForce.size() - k];
}
