#include <stdio.h>

#include <stdlib.h>

void printarr(int arr[], int size){
    for (int i = 0; i<size; i++) {
        printf("%d ", arr[i]);
        if (i == size-1){
            printf("\n");
        }
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int* Bubblesort(int arr[], int n){
    int* sortedArr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            if(sortedArr[j] > sortedArr[j+1]) {
                swap(&sortedArr[j], &sortedArr[j+1]);
            }
        }
    }
    printf("Sorted array: \n");
    printarr(sortedArr, n);
    return sortedArr;
}


int binarySearch(int arr[], int target, int size){
    int left = 0;
    int right = size-1;
    while(left <= right){
        int mid = (left+right)/2;

        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int size;
    printf("Input array size: \n");
    scanf("%d", &size);

    int arr[size];
    printf("Input elements of array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Input target:\n");
    scanf("%d", &target);

    printf("The array:\n");
    printarr(arr, size);

    int* sorted_arr = Bubblesort(arr, size);

    int position;
    position = binarySearch(sorted_arr, target ,size);
    printf("Search result: \n%d \n", position);

    free(sorted_arr);

    return 0;
}