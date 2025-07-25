// 2.1 Store random numbers in an array and find smallest and largest
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        arr[i] = rand() % 100; // random numbers 0-99
        printf("%d ", arr[i]);
    }
    printf("\n");
    int min = arr[0], max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    printf("Smallest: %d\nLargest: %d\n", min, max);
    free(arr);
    return 0;
}
