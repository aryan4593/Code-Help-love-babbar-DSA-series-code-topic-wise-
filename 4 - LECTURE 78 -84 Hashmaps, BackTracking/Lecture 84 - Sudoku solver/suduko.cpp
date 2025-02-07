#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool isSafe (int row ,int col , vector<vector<char>> &board , int val){
        for(int i = 0 ; i < 9 ; i++){
            //row
            if(board[row][i] == val + '0') return false;
            if (board[i][col] == val + '0') return false;
            if(board[3 *  (row/3) + i/3] [3*(col/3) + i %3] ==val + '0') return false;
        }


        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col]=='.'){
                    for(int val = 1 ; val <=9 ; val++){
                        if(isSafe(row ,col, board , val)){
                            
                            board[row][col] = val + '0';
                            
                            bool isCorrect = solve(board);
                            if(isCorrect) return true;
                            else board[row][col]='.'; //backtrack
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
int main(){
    Solution s1;

    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};
s1.solveSudoku(board);
    return 0;
}