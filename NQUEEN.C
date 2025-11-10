#include <stdio.h>
#include <conio.h>
#include <time.h> // Include for clock() function
#define N 4 // Change this value for different board sizes

// Define a boolean type for compatibility with old Turbo C++
#define bool int
#define true 1
#define false 0

// Global counters for analysis
long long recursive_calls = 0;
int solution_count = 0;

void printSolution(int board[N][N]);
int isSafe(int board[N][N], int row, int col);
void solveNQUtil(int board[N][N], int col);
void solveNQ();

// Prints the found solution
void printSolution(int board[N][N]) {
    int i, j;
    solution_count++;
    printf("Solution %d:\n", solution_count);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if a queen can be placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    int i, j;
    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQUtil(int board[N][N], int col) {
   int i;
    recursive_calls++;
    if (col >= N) {
        printSolution(board);
        return;
    }

    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen
            solveNQUtil(board, col + 1);
            board[i][col] = 0; // Backtrack
        }
    }
}

// Solves the N-Queens problem and measures execution time
void solveNQ() {
    int board[N][N];
    int i, j;
    clock_t start, end;
    double cpu_time_used;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    printf("Solving N-Queens for N=%d...\n\n", N);
    
    start = clock(); // Start the timer
    solveNQUtil(board, 0);
    end = clock(); // Stop the timer
    
    // Note: CLK_TCK is needed for older Turbo C++, while CLOCKS_PER_SEC is modern standard.
    // However, both will usually work in this environment.
    cpu_time_used = ((double)(end - start)) / CLK_TCK; 

    if (solution_count == 0) {
        printf("No solution exists.\n");
    }
    
    printf("Total recursive calls: %lld\n", recursive_calls);
    printf("Total solutions found: %d\n", solution_count);
    printf("Execution time: %lf seconds\n", cpu_time_used);
}

int main() {
    clrscr();
    solveNQ();
    getch();
    return 0;
}
