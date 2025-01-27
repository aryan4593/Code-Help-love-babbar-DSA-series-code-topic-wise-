#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int binarySearch(vector<int>& arr, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;

            // Handle boundary conditions
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }

            // If the mid element is less than the next element, then the peak lies on the right half
            if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
                return binarySearch(arr, mid + 1, right);
            } else {
                // Else, the peak lies on the left half
                return binarySearch(arr, left, mid - 1);
            }
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        return binarySearch(nums, 0, n - 1);
    }
};


int main()
{
    Solution s;
    vector<int> nums = {3, 4, 3, 2, 1};
    cout << s.findPeakElement(nums);
}