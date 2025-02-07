#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {

    bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        int x = row, y = col;
        // no same row
        while (y >= 0) {
            if (board[x][y] == "Q") {
                return false;
            }
            y--; // no need to check at right as we are filling board from left
                 // to right
        }

        // no same col
        // no need to check at col as we are putting only one queen in one one
        // col

        x = row, y = col;
        // no same diagonal
        while (x >= 0 && y >= 0) {
            if (board[x][y] == "Q")
                return false;
            x--, y--;
        }

        x = row, y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == "Q")
                return false;

            x++, y--;
        }

        return true;
    }

    void addSolution(vector<vector<string>>& board,
                     vector<vector<string>>& ans) {
        vector<string> temp;
        for (int i = 0; i < board.size(); i++) {
            string rowString = "";
            for (int j = 0; j < board.size(); j++) {
                rowString += board[i][j];
            }
            temp.push_back(rowString);
        }
        ans.push_back(temp);
    }

    void solve(int col, vector<vector<string>>& ans,
               vector<vector<string>>& board, int n) {
        if (col == n) {
            addSolution(board, ans);
            return;
        }

        // solve 1 case and recurrsion

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                solve(col + 1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};

// Each row will have one queen
// each col will have one queen
// No two queen atack each other

// matrix empty


int main(){
    Solution s1;
        vector<vector<string>> nQueens = s1.solveNQueens(4);

        for(auto i: nQueens){
            for(auto j: i)
                cout<<j;
            cout<<endl;
        }
    return 0;
}

//optimization

//instead of O(n) we canperform isSafe operation in O(1) using hashmap