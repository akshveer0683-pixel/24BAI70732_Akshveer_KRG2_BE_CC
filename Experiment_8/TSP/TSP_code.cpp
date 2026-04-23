#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

const int INF = INT_MAX;
int minCost;
vector<int> bestPath;

// Function to print a path
void printPath(vector<int>& path) {
    for (int city : path) {
        cout << city << " -> ";
    }
    cout << "0 (back to start)\n";
}

// TSP using Brute Force with Backtracking
void tspBruteForce(vector<vector<int>>& dist, vector<int>& path, 
                   vector<bool>& visited, int currentCost, int n, int count) {
    // Base case: all cities visited
    if (count == n) {
        // Add cost to return to starting city (0)
        int totalCost = currentCost + dist[path[n-1]][0];
        
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = path;
        }
        return;
    }
    
    // Try all unvisited cities
    for (int city = 1; city < n; city++) {
        if (!visited[city]) {
            // Pruning: if current cost already exceeds min, skip
            if (currentCost + dist[path[count-1]][city] < minCost) {
                visited[city] = true;
                path[count] = city;
                
                // Recursively visit next city
                tspBruteForce(dist, path, visited, 
                            currentCost + dist[path[count-1]][city], 
                            n, count + 1);
                
                visited[city] = false;  // Backtrack
            }
        }
    }
}

int main() {
    int n = 4;  // Number of cities
    
    // Distance matrix: dist[i][j] = distance from city i to city j
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    cout << "Traveling Salesman Problem - Brute Force\n";
    
    cout << "Number of cities: " << n << "\n";
    cout << "Starting city: 0\n\n";
    
    cout << "Distance Matrix:\n";
    cout << "    ";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << i << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << setw(3) << i << " ";
        for (int j = 0; j < n; j++) {
            cout << setw(5) << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Initialize
    minCost = INF;
    vector<int> path(n);
    vector<bool> visited(n, false);
    
    path[0] = 0;  // Start from city 0
    visited[0] = true;
    
    // Find optimal tour
    tspBruteForce(dist, path, visited, 0, n, 1);
    
    cout << "\n\nOptimal Tour:\n";
    printPath(bestPath);
    
    cout << "\nMinimum Cost: " << minCost << "\n";
    
    return 0;
}
