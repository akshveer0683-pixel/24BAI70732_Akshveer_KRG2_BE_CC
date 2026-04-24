#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solutionCount = 0;

// Function to check if placing a queen is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int n, 
            set<int>& cols, set<int>& diag1, set<int>& diag2) {
    // Check column
    if (cols.find(col) != cols.end()) return false;
    
    // Check diagonal 1 (top-left to bottom-right)
    if (diag1.find(row - col) != diag1.end()) return false;
    
    // Check diagonal 2 (top-right to bottom-left)
    if (diag2.find(row + col) != diag2.end()) return false;
    
    return true;
}

// Function to print the current solution
void printSolution(vector<vector<int>>& board, int n) {
    cout << "\nSolution " << solutionCount << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Backtracking function to solve N-Queens
void solveNQueens(vector<vector<int>>& board, int row, int n,
                  set<int>& cols, set<int>& diag1, set<int>& diag2) {
    // Base case: all queens are placed
    if (row == n) {
        solutionCount++;
        printSolution(board, n);
        return;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n, cols, diag1, diag2)) {
            // Place queen
            board[row][col] = 1;
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            // Recur to place rest of the queens
            solveNQueens(board, row + 1, n, cols, diag1, diag2);
            
            // Backtrack
            board[row][col] = 0;
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    
    // Initialize board (0 = no queen, 1 = queen)
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    // Sets for column and diagonal constraints
    set<int> cols, diag1, diag2;
    
    cout << "\n=== N-QUEENS PROBLEM ===" << endl;
    cout << "Finding all solutions for " << n << " queens...\n";
    
    solveNQueens(board, 0, n, cols, diag1, diag2);
    
    cout << "\n=== RESULTS ===" << endl;
    cout << "Total number of valid configurations: " << solutionCount << endl;
    
    return 0;
}
