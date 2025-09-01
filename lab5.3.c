/*Write a program to sort an array of n integers in O(n) worst-case time, where odd indexed 
elements are sorted in ascending order and the even indexed elements are sorted in 
descending order. The array elements are taken from a file named as aFile.txt.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 10000  // Adjust according to expected range of integers

// Counting sort for ascending order
void countingSortAsc(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

// Counting sort for descending order
void countingSortDesc(int arr[], int n) {
    countingSortAsc(arr, n);
    // Reverse for descending
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    FILE *fp = fopen("aFile.txt", "r");
    if (!fp) {
        printf("Error: Could not open aFile.txt\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n); // First value in file is number of elements
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i]) != 1) {
            printf("Error reading element %d\n", i);
            fclose(fp);
            free(arr);
            return 1;
        }
    }
    fclose(fp);

    // Separate even-indexed and odd-indexed elements
    int evenCount = (n + 1) / 2;
    int oddCount = n / 2;
    int *evenArr = (int *)malloc(evenCount * sizeof(int));
    int *oddArr = (int *)malloc(oddCount * sizeof(int));

    int ei = 0, oi = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) evenArr[ei++] = arr[i];
        else oddArr[oi++] = arr[i];
    }

    // Sort separately
    countingSortDesc(evenArr, evenCount);
    countingSortAsc(oddArr, oddCount);

    // Merge back into original array
    ei = oi = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) arr[i] = evenArr[ei++];
        else arr[i] = oddArr[oi++];
    }

    // Output result
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    free(evenArr);
    free(oddArr);

    return 0;
}