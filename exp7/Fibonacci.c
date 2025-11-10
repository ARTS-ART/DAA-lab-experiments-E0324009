#include <stdio.h>
#include<time.h>
int main() {
int n, t1 = 0, t2 = 1, nextTerm;
clock_t start,end;
printf("Enter the number of terms: ");
scanf("%d", &n);
printf("Fibonacci Series: %d, %d", t1, t2);
start=clock();
for (int i = 3; i <= n; ++i) {
nextTerm = t1 + t2; 
printf(", %d", nextTerm); // Print the next term
t1 = t2; // Update t1 to the previous t2
t2 = nextTerm; // Update t2 to the newly calculated nextTerm
}
end=clock();
double cpu_time_used=((double)(end-start)/CLOCKS_PER_SEC);
printf("\n");
printf("time taken is:%f sec",cpu_time_used);
printf("\n"); // Newline for cleaner output
return 0;
}
