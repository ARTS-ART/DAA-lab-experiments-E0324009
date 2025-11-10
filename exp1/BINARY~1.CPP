#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Recursive Binary Search Function
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (high < low) {
	return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
	return mid;
    } else if (arr[mid] > key) {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    } else {
        return recursiveBinarySearch(arr, mid + 1, high, key);
    }
}


void main() {
    int n, key,result,i;
    int arr[5];
    clock_t start, end;
    double cpu_time_used;
    clrscr();

    printf("Enter the size of the array: ");
    scanf("%d", &n);


    printf("Enter the sorted array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    start = clock();

    result= recursiveBinarySearch(arr, 0, n - 1, key);


  

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


    if (result != -1) {
        printf("\nElement found at index %d\n", result);
    } else {
	printf("\nElement not found\n");
    }
  end = clock();
     printf(" execution time per search: %f seconds\n", cpu_time_used);

    getch();
}
