#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int ptr1 = 0, ptr2 = 0; // two pointers approach
    vector<int> v3;
    
    while (ptr1 < m && ptr2 < n) {
        if (nums1[ptr1] < nums2[ptr2]) {
            v3.push_back(nums1[ptr1]);
            ptr1++;
        } else {
            v3.push_back(nums2[ptr2]);
            ptr2++;
        }
    }
    
    while (ptr1 < m) {
        v3.push_back(nums1[ptr1]);
        ptr1++;
    }
    
    while (ptr2 < n) {
        v3.push_back(nums2[ptr2]);
        ptr2++;
    }
    
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << endl;
        
    }
}


// int main() {
//     vector<int>

    
        
//     for (int i =0;i<v3.size();i++){
//         cout<<v3[i]<<endl;
        
//     }
        
        
    // }
int main (){
    vector <int> nums1= {1,2,3,5,7,9};
    vector <int> nums2={2,4,6};
    merge(nums1,6,nums2,3);
    vector<int> nums3;

    return 0;
}