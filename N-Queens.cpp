#include <iostream>
#include <vector>

using namespace std;

class NQueen {
private:
    int N; // Size of the board (NxN)

public:
    NQueen(int size) : N(size) {}

    // Main function to solve the N-Queen problem
    bool solveNQ() {
        vector<vector<int>> board(N, vector<int>(N, 0)); // Initialize the board with all zeros

        if (!solveNQUtil(board, 0)) {
            cout << "No solution exists" << endl;
            return false;
        }

        printSolution(board);
        return true;
    }

private:
    // A utility function to solve N-Queen problem recursively
    bool solveNQUtil(vector<vector<int>>& board, int col) {
        // Base case: If all queens are placed
        if (col >= N) {
            return true;
        }

        // Try placing the queen in all rows one by one in the current column
        for (int row = 0; row < N; row++) {
            if (isSafe(board, row, col)) { // Check if it is safe to place the queen
                board[row][col] = 1; // Place the queen

                // Recursively place the rest of the queens
                if (solveNQUtil(board, col + 1)) {
                    return true;
                }

                // If placing queen here leads to no solution, backtrack
                board[row][col] = 0; // Remove the queen
            }
        }

        // If no row is valid for the current column, return false
        return false;
    }

    // A utility function to check if a queen can be placed on board[row][col]
    bool isSafe(const vector<vector<int>>& board, int row, int col) {
        int i, j;

        // Check for any queen in the same row on the left side
        for (i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // Check for any queen in the upper diagonal on the left side
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check for any queen in the lower diagonal on the left side
        for (i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // A utility function to print the solution
    void printSolution(const vector<vector<int>>& board) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4; // Example: Solve for a 4x4 board
    NQueen Queen(n);
    Queen.solveNQ();

    return 0;
}
