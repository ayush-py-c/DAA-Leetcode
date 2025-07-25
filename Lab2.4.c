// 2.4 Product of all elements except at current index, no extra array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter n (>1): ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        arr[i] = rand()%10+1;
        printf("%d ", arr[i]);
    }
    printf("\nOutput: ");
    for(int i=0; i<n; i++) {
        int prod=1;
        for(int j=0; j<n; j++) {
            if(i!=j) prod*=arr[j];
        }
        printf("%d ", prod);
    }
    printf("\n");
    free(arr);
    return 0;
}
