#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArraySample(int arr[], int n) {
    if (n <= 20) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        // Print only first 10 and last 10
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("... ");
        for (int i = n - 10; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, i;

    // Print CSV header
    printf("Size,Time(seconds)\n");

    // Test for sizes 1000, 2000, ..., 9000
    for (n = 1000; n <= 9000; n += 1000) {
        int *arr = (int*)malloc(n * sizeof(int));

        // Generate random array
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 10000;  // values between 0 and 9999
        }

        // Measure time
        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print execution time
        printf("%d,%f\n", n, time_taken);

        // Print part of sorted output
        printf("Sorted output for size %d:\n", n);
        printArraySample(arr, n);
        printf("\n");

        free(arr);
    }

    return 0;
}


