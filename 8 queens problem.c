#include <stdio.h>
#include <stdlib.h>
#define N 8 // Size of the chessboard (N x N)

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1; // The position is safe
}

// Recursive function to solve the N-Queens problem
int solveNQueens(int board[N][N], int col) {
    // Base case: If all queens are placed, return success
    if (col >= N) {
        printSolution(board);
        return 1;
    }

    int res = 0; // To track if any solution is found

    // Try placing a queen in every row of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            // Recursively place the rest of the queens
            res |= solveNQueens(board, col + 1);

            board[i][col] = 0; // Backtrack: Remove the queen
        }
    }

    return res; // Return whether any solution was found
}

// Function to start solving the problem
void solve() {
    int board[N][N] = {0}; // Initialize the chessboard with 0

    if (!solveNQueens(board, 0)) {
        printf("No solutions exist.\n");
    }
}

// Main function
int main() {
    printf("Solutions to the Eight Queens problem:\n\n");
    solve();
    return 0;
}