#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function
void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1,n2=r-m;
    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    free(L); free(R);
}

// Merge Sort
void mergeSort(int arr[], int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// Print first 10 and last 10 elements
void printArraySample(int arr[], int n){
    int i;
    for(i=0;i<10 && i<n;i++) printf("%d ",arr[i]);
    if(n>20) printf("... ");
    for(i=(n>20?n-10:10); i<n; i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    printf("Merge Sort:\n");

    for(int n=1000;n<=9000;n+=1000){
        int *arr=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++) arr[i]=rand()%10000;

        printf("\nArray sample before sorting (size %d):\n", n);
        printArraySample(arr,n);

        clock_t start=clock();
        mergeSort(arr,0,n-1);
        clock_t end=clock();
        double time_taken=((double)(end-start))/CLOCKS_PER_SEC;

        printf("Array sample after sorting:\n");
        printArraySample(arr,n);
        printf("Execution time: %f seconds\n", time_taken);

        free(arr);
    }
    return 0;
}

