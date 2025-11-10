#include <stdio.h>
#include <conio.h> // For clrscr() and getch()
#include <time.h>
#include <stdlib.h> // For exit() and dynamic memory allocation

// Recursive Linear Search Function
int recursiveLinearSearch(int arr[], int size, int key, int index) {
    if (index >= size) {
        return -1; // Base case: not found
    }
    if (arr[index] == key) {
        return index; // Base case: element found
    }
    // Recursive call
    return recursiveLinearSearch(arr, size, key, index + 1);
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

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    start = clock(); // Start time

    // Call the recursive function to search for the key
    int result = recursiveLinearSearch(arr, n, key, 0);

    end = clock(); // End time

    cpu_time_used = ((double)(end - start)) / CLK_TCK; // Use CLK_TCK for Turbo C++

    if (result != -1) {
        printf("\nElement found at index %d\n", result);
    } else {
        printf("\nElement not found\n");
    }

    printf("Execution time: %f seconds\n", cpu_time_used);

    free(arr); // Free the dynamically allocated memory
    getch(); // Wait for a key press to hold the output screen
}