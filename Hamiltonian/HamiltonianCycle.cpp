#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> adjMatrix;
vector<int> path;
bool cycleFound = false;

// Function to print the Hamiltonian cycle
void printCycle() {
    cout << "\nHamiltonian Cycle found:\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << " -> " << path[0] << endl;
}

// Backtracking function to find Hamiltonian cycle
void findHamiltonianCycle(int curr, int count) {
    // Base case: all vertices visited
    if (count == n) {
        // Check if there's an edge from current vertex to starting vertex (0)
        if (adjMatrix[curr][0] == 1) {
            cycleFound = true;
            printCycle();
        }
        return;
    }
    
    // Try going to all adjacent vertices
    for (int next = 1; next < n; next++) {
        // Check if next vertex is connected and not yet visited
        if (adjMatrix[curr][next] == 1) {
            bool visited = false;
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == next) {
                    visited = true;
                    break;
                }
            }
            
            if (!visited) {
                path.push_back(next);
                findHamiltonianCycle(next, count + 1);
                
                // Backtrack only if cycle not found
                if (!cycleFound) {
                    path.pop_back();
                }
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    // Initialize adjacency matrix
    adjMatrix.resize(n, vector<int>(n, 0));
    
    cout << "Enter the adjacency matrix (1 for edge, 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    
    cout << "\n=== HAMILTONIAN CYCLE PROBLEM ===" << endl;
    cout << "Finding Hamiltonian cycle starting from vertex 0...\n";
    
    // Start from vertex 0
    path.push_back(0);
    findHamiltonianCycle(0, 1);
    
    cout << "\n=== RESULT ===" << endl;
    if (!cycleFound) {
        cout << "No Hamiltonian cycle exists in this graph." << endl;
        return 0;
    }
    
    return 0;
}
