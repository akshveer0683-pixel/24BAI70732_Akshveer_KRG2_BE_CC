#include <iostream>
#include <vector>
using namespace std;

// Binary Search(Iterative Approach)
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Element found
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Search in right half
        }
        else {
            right = mid - 1;  // Search in left half
        }
    }
    return -1;  // Element not found
}

// Binary Search(Recursive Approach)
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;  // Element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
    else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int target = 23;
    
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\nTarget: " << target << "\n";
    
    // Iterative approach
    int resultIter = binarySearchIterative(arr, target);
    cout << "\nIterative Result: ";
    if (resultIter != -1) {
        cout << "Element found at index " << resultIter << "\n";
    } else {
        cout << "Element not found\n";
    }
    
    // Recursive approach
    int resultRec = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    cout << "Recursive Result: ";
    if (resultRec != -1) {
        cout << "Element found at index " << resultRec << "\n";
    } else {
        cout << "Element not found\n";
    }
    
    return 0;
}
