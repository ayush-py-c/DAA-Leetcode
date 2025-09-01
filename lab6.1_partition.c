// Partition procedure demonstration for array with roll number 2328159
#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    printf("Initial array: "); printArray(arr, high+1);
    printf("Pivot: %d\n", pivot);
    for(int j = low; j < high; j++) {
        printf("Comparing arr[%d]=%d with pivot=%d\n", j, arr[j], pivot);
        if(arr[j] <= pivot) {
            i++;
            printf("  Swap arr[%d]=%d and arr[%d]=%d\n", i, arr[i], j, arr[j]);
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            printArray(arr, high+1);
        }
    }
    printf("Final swap arr[%d]=%d and arr[%d]=%d (pivot)\n", i+1, arr[i+1], high, arr[high]);
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    printArray(arr, high+1);
    printf("Pivot index after partition: %d\n", i+1);
    return i+1;
}

int main() {
    int arr[] = {2, 3, 2, 8, 1, 5, 9, 7, 6, 5, 9}; // 2328159 digits
    int n = sizeof(arr)/sizeof(arr[0]);
    partition(arr, 0, n-1);
    return 0;
}
