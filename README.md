# Sudoku_Solver
The repository contains a C++ code to solve a Sudoku Puzzle.

Work Flow of the Program:  
1] Enter the sudoku grid values each at a time. If the value is not present (needs to be filled during solving), enter the value as zero.  
2] The main function calls a function named solveSudoku() which solves the suduko using backtracing.  
&nbsp; &nbsp; a] Vectors for row, col and block are initialized to store the already present numbers in the board.  
&nbsp; &nbsp; b] The main function to solve the board is then called named solve() which works on the principle of Backtracking.  
&nbsp; &nbsp; c] The solve() function searches for a zero (which denotes an empty space) and tries to fill it with the first possible valid number available from the range of 1 to 9. In case, no such number is found, the solution backtracks to the last known point and tries the next possible number and so and so forth.  
&nbsp; &nbsp; d] Other helper functions include removeNumber() and isValid() to remove numbers from the set of numbers present during backtracking from the vectors named row, col and blk. isValid() checks the vectors row, col and blk to ascertain if the number is already present in those specific row, column and block.

![Alt text](Screenshots/Input.png?raw=true "Input")  
![Alt text](Screenshots/Output.png?raw=true "Output")
