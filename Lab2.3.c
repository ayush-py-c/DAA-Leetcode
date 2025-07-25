// 2.3 Rearrange array so all even numbers are followed by all odd numbers
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
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\nRearranged: ");
    for(int i=0; i<n; i++) {
        if(arr[i]%2==0) printf("%d ", arr[i]);
    }
    for(int i=0; i<n; i++) {
        if(arr[i]%2!=0) printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
