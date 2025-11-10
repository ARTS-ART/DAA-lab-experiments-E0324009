#include <iostream.h>
#include <conio.h>

// Structure to store both maximum and minimum values
struct Pair {
    int max;
    int min;
};

// Function to find maximum and minimum using divide and conquer
struct Pair maxMinDivideConquer(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // Base case 1: If there is only one element in the array
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Base case 2: If there are two elements in the array
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Recursive step: If there are more than two elements
    mid = (low + high) / 2;
    left = maxMinDivideConquer(arr, low, mid);
    right = maxMinDivideConquer(arr, mid + 1, high);

    // Compare and get the overall maximum
    if (left.max > right.max) {
        result.max = left.max;
    } else {
        result.max = right.max;
    }

    // Compare and get the overall minimum
    if (left.min < right.min) {
        result.min = left.min;
    } else {
        result.min = right.min;
    }

    return result;
}

int main() {
    clrscr(); // Clear the console screen

    int arr[] = {16, 4, 26, 14, 33, 64, 46};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair result = maxMinDivideConquer(arr, 0, n - 1);
    
    cout << "Maximum element is: " << result.max << "\n";
    cout << "Minimum element is: " << result.min << "\n";

    getch(); // Wait for a keypress
    return 0;
}
