#include <stdio.h>
#include <conio.h>
#include <time.h>

#define MAX_N 20

// The function prototype is placed at the top for compatibility
void findSubset(int current_set[], int current_subset[], int current_n, int index, int target, int currentSum);

void findSubset(int current_set[], int current_subset[], int current_n, int index, int target, int currentSum) {
    int i;
    
    if (currentSum == target) {
        printf("Subset found: ");
        for (i = 0; i < index; i++) {
            printf("%d ", current_subset[i]);
        }
        printf("\n");
        return;
    }

    if (currentSum > target || current_n <= 0) { // Added boundary check
        return;
    }

    // Include the current element
    current_subset[index] = current_set[0];
    findSubset(current_set + 1, current_subset, current_n - 1, index + 1, target, currentSum + current_set[0]);

    // Exclude the current element
    findSubset(current_set + 1, current_subset, current_n - 1, index, target, currentSum);
}

void main() {
    int n, target;
    int i;
    int set[MAX_N], subset[MAX_N];
    clock_t start_time, end_time;
    double elapsed_time;

    clrscr();

    printf("Enter the number of elements in the set (max %d): ", MAX_N);
    scanf("%d", &n);

    if (n > MAX_N || n < 1) {
	printf("Invalid input size.\n");
	getch();
	return;
    }

    printf("Enter the elements of the set: ");
    for (i = 0; i < n; i++) {
	scanf("%d", &set[i]);
    }
     start_time = clock();
    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum %d:\n", target);


    findSubset(set, subset, n, 0, target, 0);
      end_time = clock();

    // CLK_TCK is used for Turbo C++ compatibility
    elapsed_time = (double)(end_time - start_time) / CLK_TCK;
    printf("\nExecution time: %f seconds\n", elapsed_time);

    getch();
}
