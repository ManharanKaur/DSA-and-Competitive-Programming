#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, 
        startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<char>> & board){
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            if(board[row][col] == '.'){ // empty cell
                for(char num = '1'; num <= '9'; num++){
                    if(isSafe(board,row,col,num)){
                        board[row][col] = num;

                        if(solveSudoku(board))
                            return true;
                        
                            board[row][col] = '.'; //backtracking
                    }
                }
                return false; // no valid num found
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<char>> & board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
} 

int main() {
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

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}