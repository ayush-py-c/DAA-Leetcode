// 2.2 Store random numbers with duplicates, find total duplicates and most repeating
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
        arr[i] = rand() % (n/2 + 2); // force some duplicates
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Count duplicates
    int dupCount = 0;
    int checked[n];
    for(int i=0; i<n; i++) checked[i]=0;
    for(int i=0; i<n; i++) {
        if(checked[i]) continue;
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i]==arr[j]) {
                count++;
                checked[j]=1;
            }
        }
        if(count>1) dupCount++;
    }
    printf("Total duplicate elements: %d\n", dupCount);
    // Most repeating element
    int maxFreq=0, mostRep=arr[0];
    for(int i=0; i<n; i++) {
        int count=1;
        for(int j=i+1; j<n; j++) {
            if(arr[i]==arr[j]) count++;
        }
        if(count>maxFreq) {
            maxFreq=count;
            mostRep=arr[i];
        }
    }
    printf("Most repeating element: %d (repeats %d times)\n", mostRep, maxFreq);
    free(arr);
    return 0;
}
