#include <stdio.h>
#include <conio.h>  // For clrscr() and getch()
#include <stdlib.h> // For malloc(), free(), and exit()
#include <time.h>   // For time measurement

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // key found
        } else if (arr[mid] < key) {
            low = mid + 1; // search right half
        } else {
            high = mid - 1; // search left half
        }
    }
    return -1; // not found
}

void main() {
    int n, key, *arr, i;
    clock_t start, end;
    double cpu_time_used;

    clrscr(); // Clear the console screen

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array dynamically
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        getch();
        exit(1);
    }

    printf("Enter the sorted array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    start = clock(); // Start time

    // Call the binary search function
    int result = binarySearch(arr, n, key);

    end = clock(); // End time

    cpu_time_used = ((double)(end - start)) / CLK_TCK; // Use CLK_TCK for Turbo C++

    if (result != -1) {
        printf("\nElement found at index %d\n", result);
    } else {
        printf("\nElement not found\n");
    }

    printf("Execution time: %f seconds\n", cpu_time_used);

    free(arr); // Free the dynamically allocated memory
    getch();   // Wait for a key press to hold the output screen
}