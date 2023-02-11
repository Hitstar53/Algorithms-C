#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//data function
void dataInput() {
    //generate 100000 random numbers
    srand(time(NULL));
    for (int i=0;i<100000; i++)
    {
        int temp = rand()%1000000000;
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
//merge sort algorithm
void merge(long arr[],long temp[],int mid,int left,int right) {
    int i,left_end,size,temp_pos;
    left_end = mid-1;
    temp_pos = left;
    size = right-left+1;
    while((left<=left_end)&&(mid<=right)) {
        if(arr[left]<=arr[mid]) {
            temp[temp_pos] = arr[left];
            temp_pos = temp_pos+1;
            left = left+1;
        }
        else {
            temp[temp_pos] = arr[mid];
            temp_pos = temp_pos+1;
            mid = mid+1;
        }
    }
    while(left<=left_end) {
        temp[temp_pos] = arr[left];
        left = left+1;
        temp_pos = temp_pos+1;
    }
    while(mid<=right) {
        temp[temp_pos] = arr[mid];
        mid = mid+1;
        temp_pos = temp_pos+1;
    }
    for(i=0;i<=size;i++) {
        arr[right] = temp[right];
        right = right-1;
    }
}
void mergeSort(long arr[],long temp[],int left,int right) {
    int mid;
    if(right>left) {
        mid = (right+left)/2;
        mergeSort(arr,temp,left,mid);
        mergeSort(arr,temp,mid+1,right);
        merge(arr,temp,mid+1,left,right);
    }
}
//quick sort algorithm
int partition(long arr[], int low, int high) {
    int left, right, pivot_item = arr[low];
    left = low;
    right = high;
    while(left<right) {
        while(arr[left]<=pivot_item) {
            left++;
        }
        while(arr[right]>pivot_item) {
            right--;
        }
        if(left<right) {
            swap(&arr[left], &arr[right]);
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}
void quickSort(long arr[], int low, int high) {
    int pivot;
    if (low<high) {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}
int main(int argc, char const *argv[])
{
    //gen data
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
    printf("Size\tMerge Sort\tQuick Sort\n");
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<s;j++)
        {
            arr1[j] = arr[j];
            arr2[j] = arr[j];
        }
        double diff1, diff2;
        struct timespec start, end;
        //merge sort
        clock_gettime(CLOCK_MONOTONIC, &start);
        long temp[s];
        mergeSort(arr1, temp, 0, s-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff1 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        //quick sort
        clock_gettime(CLOCK_MONOTONIC, &start);
        quickSort(arr2, 0, s-1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff2 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("%d\t%f\t%f\n", s, diff1, diff2);
        s += 100;
    }
    return 0;
}
