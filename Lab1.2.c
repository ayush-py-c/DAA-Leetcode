// Given an array arr[] of size N, find the prefix sum of the array. A prefix
// sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
// arr[0] + arr[1] + arr[2] . . . arr[i].

#include <stdio.h>
int findPrefixSum(int arr[], int n, int prefixSum[]) {
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];
    findPrefixSum(arr, n, prefixSum);
    for(int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    return 0;
}