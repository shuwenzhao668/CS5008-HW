#include <stdio.h>

void printarr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%ld ", arr[i]);
        if(i == size-1) {
            printf("\n");
        }
    }
}

int int_bi(int a) {
    long int result = 0;
    int base = 1;

    while(a > 0) {
        result += (a % 2) * base;
        a = a/2;
        base = base * 10;
    }

    return result;
}

int bi_int(int a) {
    int result = 0;
    int base = 1;

    while(a > 0) {
        result += (a % 10) * base;
        a = a/10;
        base = base * 2;
    }

    return result;
}

int linearSearch(int arr[], int target, int size) {
    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            return i;
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
    for (int i = 0;i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("Input target:\n");
    scanf("%d", &target);

    printf("The array:\n");
    printarr(arr, size);

    int converted_arr[size];
    for (int i = 0; i<size; i++){
        converted_arr[i] = int_bi(arr[i]);
    }
    printf("Converted array: \n");
    printarr(converted_arr,size);

    printf("Converted target: \n");
    int target_converted;
    target_converted = int_bi(target);
    printf("%d \n", target_converted);

    int position;
    position = linearSearch(converted_arr, target_converted, size);
    printf("Search result: \n%d \n", position);

    int original_arr[size];
    for (int i = 0; i<size; i++){
        original_arr[i] = bi_int(converted_arr[i]);
    }
    printf("Original array:\n");
    printarr(original_arr,size);

    int original_target = bi_int(target_converted);
    printf("Original target:\n");
    printf("%d", original_target);
    printf("\n");

    return 0;
}
