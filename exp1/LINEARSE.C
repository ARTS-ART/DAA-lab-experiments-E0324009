#include <stdio.h>
#include <conio.h>
#include <time.h>
void main(){
int i,s,n=5;
int a[5];
clock_t start,end;
double cpu_time_used;
clrscr();
start=clock();
for(i=0;i<n;i++){
printf("a[%d]: ",i+1);
scanf("%d",&a[i]);}
printf("The elements are \n: ");
for(i=0;i<n;i++){
printf("%d, ",a[i]);}
printf("\n enter element to search: ");
scanf("%d",&s);
for(i=0;i<n;i++){
 if(a[i]==s){
printf("The element %d found at index %d ",s,i); }  }
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nExecution time: %f seconds",cpu_time_used);
getch();}
