#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//data function
void dataInput() {
    //generate 100000 random numbers
    for (int i=0;i<100000; i++)
    {
        int temp = rand() % 1000000000;
        FILE *fptr;
        fptr = fopen("data.txt", "a");
        fprintf(fptr, "%d\n", temp);
        fclose(fptr);
    }
}
//swap function
void swap(long *xp, long *yp) {
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//selection sort algorithm
void selectionSort(long arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        swap(&arr[min_idx], &arr[i]);
    }
}
//insertion sort algorithm
void insertionSort(long arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
int main() {
    //generate data
    // dataInput();
    //read data from file
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    long arr[100000], arr1[100000], arr2[100000];
    for (int i = 0; i < 100000; i++)
    {
        fscanf(fptr, "%8ld", &arr[i]);
    }
    fclose(fptr);
    int s = 100;
    printf("Size\tSelection Sort\tInsertion Sort\n");
    for(int i=0;i<=1000;i++) {
        for (int j = 0; j < 100000; j++) {
            arr1[j] = arr[j];
            arr2[j] = arr[j];
        }
        double diff1, diff2;
        struct timespec start, end;
        int i;
        clock_gettime(CLOCK_MONOTONIC, &start);
        selectionSort(arr1, s);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff1 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000.0;
        clock_gettime(CLOCK_MONOTONIC, &start);
        insertionSort(arr2, s);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000000000.0;
        printf("%d\t%f\t%f\n", s, diff1, diff2);
        s+=100;
    }
    return 0;
}