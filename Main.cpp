#include<iostream>
#include<vector>

using namespace std;

//Vectors store the digits present in each row, column and a box of size 3 * 3.
vector<short> row;
vector<short> col;
vector<short> blk;

/*
Function to store the digits present in each row, column and box of size 3 * 3
Example: If board[3][2] = 6 (Consider 0 index board for every function), then the 6th bit of
row[6] is set. Similarly, the 6th bit of col[2] is set and the 6th bit of blk[3] is set.
*/
void insertNumber(vector<vector<int>>& board, int i, int j) {
    short ind = 1 << board[i][j];

    row[i] |= ind;
    col[j] |= ind;
    blk[i/3 * 3 + j/3] |= ind;
}

/*
Function to remove the digit we added during the backtracking proceure in case the sudoku rules
are broken. To remove the digits we, clear the bit is the respective row, column and block.
Example: If we have added board[4][5] = 9 during the backtracking procedure and at a later stage
conclude that it breaks sudoku rules, we clear the 9th bits for row[4], col[5] and blk[4].
*/
void removeNumber(vector<vector<int>>& board, int i, int j) {
    short ind = ~(1 << board[i][j]);

    row[i] &= ind;
    col[j] &= ind;
    blk[i/3 * 3 + j/3 ] &= ind;
}

/*
Function to check during backtracking if a number is already present in the respective row, column
and block.
*/
bool isValid(vector<vector<int>>& board, int i, int j, int num) {
    short ind = 1 << num;

    if(row[i] & ind || col[j] & ind || blk[i/3 * 3 + j/3] & ind) {
        return false;
    }

    return true;
}

/*
Function to solve the Sudoku board. If a zero is encountered, the innermost for loop tries to fill
it with the first possible digit from the range [1,9] and moves ahead. In case, the current combination
fails, it backtracks and tries the next possible digit and then again moves forward till no zeroes
are present on the board.
*/
bool solve(vector<vector<int>>& board) {
    int i, j, k;

    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {

            if(!board[i][j]) {
                
                for(k=1; k<=9; k++) {

                    if(isValid(board, i, j, k)) {
                        board[i][j] = k;
                        insertNumber(board, i, j);

                        if(solve(board)) {
                            return true;
                        }

                        else {
                            removeNumber(board, i, j);
                            board[i][j] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

/*
Function to intialize the vectors to store the already present digits in the board and call the 
backtracking function.
*/
void solveSudoku(vector<vector<int>>& board) {
    row.resize(9, 0);
    col.resize(9, 0);
    blk.resize(9, 0);
    int i, j;

    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(board[i][j]) {
                insertNumber(board, i, j);
            }
        }
    }

    solve(board);
}

/*
Main function to accept the Suduko board, solve it and display it.
*/
int main() {
    vector<vector<int>> board (9, vector<int> (9, 0));
    int i, j, inp;
    cout<<"Enter values in the Sudoku grid between 1 to 9."<<endl;
    cout<<"If the grid value is unknown, press 0"<<endl;

    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            cout<<"Enter the value of grid["<<i+1<<"]["<<j+1<<"] : ";
            cin>>board[i][j];
        }
    }

    solveSudoku(board);

    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}