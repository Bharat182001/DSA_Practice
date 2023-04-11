// https://leetcode.com/problems/sudoku-solver/description/

// Approach: Using Backtracking, done by both striver's for loop approach and my (traversal using recursion only approach)


class Solution {
public:
    int n;
    bool isSafeToPlace(char ch, int r, int c, vector<vector<char>> &board) {
        for(int i=0; i<9; i++) {
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
            // more intuitive way of checking subcube
            if(board[3*(r/3)+i/3][3*(c/3)+(i%3)] == ch) return false;
        }
        return true;
    }

    bool solve2(int row, int col, vector<vector<char>> &board) {

        if(col==n) {
            row++;
            col=0;
        }
        if(row==n) {
            return true;
        }

        if(board[row][col] != '.') {
            if(solve2(row, col+1, board)) return true;
            else return false;
        }
        else{
            for(char ch='1'; ch<='9'; ch++) {
                if(isSafeToPlace(ch, row, col, board)) {
                    board[row][col] = ch;

                    if(solve2(row, col+1, board)==true) return true;
                    else board[row][col]='.';
                }
            }
            return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // we have 3 types of check for a particular cell: 
        // 1: check for that number in that row
        // 2: check for that number in that col
        // 3: check for that number in that subcube of 3x3
        // now how to find subcube : initital index of subcube: { 3*(r/3), 3*(c/3) }, end index: { 3*(r/3)+2, 3*(c/3)+2 }

        n=board.size();
        solve2(0, 0, board);
        // solve(board);
    }
};
