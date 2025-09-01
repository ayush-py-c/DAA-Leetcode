// Write a program to recursively implement Binary Search using divide and conquer 
// method. Determine the time required to search an element in an array of n integers. Repeat 
// the experiment for different values of n, the number of elements in the list to be searched 
// and plot a graph of the time taken versus n. The n integers can be generated randomly.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
        return binarySearch(arr, mid + 1, high, target);
    }
    return -1;
}
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    srand(time(0));
    int n = 1000; 
    int step = 1000; 
    int max_n = 10000; 
    while (n <= max_n) {
        int *arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000; 
        }

        qsort(arr, n, sizeof(int),compare);
        int target = rand() % 10000;
        clock_t start = clock();
        int result = binarySearch(arr, 0, n - 1, target);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for n=%d: %f seconds\n", n, time_taken);
        free(arr);
        n += step;
    }
    return 0;
}
