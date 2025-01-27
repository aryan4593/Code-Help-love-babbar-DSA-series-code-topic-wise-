#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int e = (row*col )-1;
        int s =0;
        int mid = s+ (e-s)/2;

        while (s<=e){
            if (matrix[mid/col][mid%col]==target){
                return true;
            }
            else if (matrix[mid/col][mid%col]>target){
                e = mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }

        return false;
    }
};

int main (){

}