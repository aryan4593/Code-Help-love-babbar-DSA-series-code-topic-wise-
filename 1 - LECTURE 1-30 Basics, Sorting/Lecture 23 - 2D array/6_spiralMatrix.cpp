/*
1.print start row
2.print end col
3.print last row(backward)
4.print starting col upward

*/
#include<iostream>
using namespace std;
#include<vector>

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Handle empty matrix edge case
        if (matrix.empty()) return {};  // ADDED

        int stRow = 0, stCol = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int endRow = row - 1, endCol = col - 1;
        int count = 0;
        int total = row * col;
        vector<int> ans;

        while (count < total) {
            // Print starting row
            for (int index = stCol; index <= endCol && count < total; index++) {  // CHANGED
                ans.push_back(matrix[stRow][index]);
                count++;
            }
            stRow++;
            
            // Printing end column
            for (int index = stRow; index <= endRow && count < total; index++) {  // CHANGED
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;

            // Printing ending row
            for (int index = endCol; index >= stCol && count < total; index--) {  // CHANGED
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            // Print starting column
            for (int index = endRow; index >= stRow && count < total; index--) {  // CHANGED
                ans.push_back(matrix[index][stCol]);
                count++;
            }
            stCol++;
        }

        return ans;
    }


int main (){
    vector<std::vector<int>> vec = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    spiralOrder(vec);
    return 0;
}