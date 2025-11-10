#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print first 10 and last 10 elements
void printArraySample(int arr[], int n) {
    int i;
    for(i=0;i<10 && i<n;i++) printf("%d ",arr[i]);
    if(n>20) printf("... ");
    for(i=(n>20?n-10:10); i<n; i++) printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    printf("Quick Sort:\n");

    for(int n=1000;n<=9000;n+=1000) {
        int *arr = (int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++) arr[i] = rand()%10000;

        printf("\nArray sample before sorting (size %d):\n", n);
        printArraySample(arr, n);

        // Measure time
        clock_t start = clock();
        quickSort(arr, 0, n-1);
        clock_t end = clock();
        double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

        printf("Array sample after sorting:\n");
        printArraySample(arr, n);
        printf("Execution time: %f seconds\n", time_taken);

        free(arr);
    }
    return 0;
}

