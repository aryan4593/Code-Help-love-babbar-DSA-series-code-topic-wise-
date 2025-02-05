#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix){
    vector <int>ans;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i =0;i<col;i++){

        for (int j = row-1;j>=0;j++){
            ans.push_back(matrix[j][i]);
        }
        
    }
    int m =0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; i < col; j++)
            {
                matrix[i][j]= ans[m];
                m++;
            }
            
        }
}

int main()
{

    return 0;
}