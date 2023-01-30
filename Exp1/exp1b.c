#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//input function
void dataInput() {
    //generate 100000 random numbers
    for (int i=0;i<100000; i++)
    {
        int temp = rand() % 100000000;
        FILE *fptr;
        fptr = fopen("data.txt", "a");
        fprintf(fptr, "%d\n", temp);
        fclose(fptr);
    }
}
//swap function
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//selection sort algorithm
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
//insertion sort algorithm
void insertionSort(int arr[], int n) {
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
void timer() {
    //read data from file
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    int arr[100000];
    for (int i=0;i<100000; i++)
    {
        fscanf(fptr, "%d", &arr[i]);
    }
    fclose(fptr);
    //initialise time variable for selection sort
    clock_t st, et;
    st = clock();
    int j;
    //call selection sort function
    for(int i=100,j=0;j<=1000;i+=100,j+=1)
    {
        int arr2[100000];
        for (int i=0;i<100000; i++)
        {
            arr2[i] = arr[i];
        }
        selectionSort(arr2, i);
        et = clock();
        double t = (double)(et-st)/CLOCKS_PER_SEC;
        printf("Time taken for selection sort %d: %fs \n",i,t);
    }
}
int main() {
    dataInput();
    timer();
    return 0;
}