#include<iostream>
using namespace std;

class Solution {
//make heap for first k element;
// for remaining element if element > heap.top then replace it then heapify it 
void heapify (vector<int> & nums , int n , int i){
    int smallest = i;
    int left = 2 * i +1;
    int right = 2 * i +2;

    if(left < n and nums[left] < nums[smallest]){
        smallest = left;
    }
    if(right < n and nums[right] < nums[smallest]){
        smallest = right;
    }

    if(i != smallest){
        swap (nums[smallest] , nums[i] );
        heapify(nums, n, smallest);
    }
}
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i = k-1; i>=0; i--){
            heapify(nums,k,i);
        }

        for(int i = k ; i< nums.size(); i++){
            if(nums[0] < nums[i]) {
                swap(nums[0], nums[i]);
                heapify(nums,k, 0);
            }
        }

        return nums[0];
    }
};