#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *arr = NULL;
int n = 0;

void iterativeMaxMin(int *arr, int n, int *max, int *min, int *comparisons) {
    *max = *min = arr[0];
    *comparisons = 0;

    for (int i = 1; i < n; i++) {
        (*comparisons)++;
        if (arr[i] > *max) *max = arr[i];
        else {
            (*comparisons)++;
            if (arr[i] < *min) *min = arr[i];
        }
    }
}

void dacMaxMin(int *arr, int low, int high, int *max, int *min, int *comparisons) {
    if (low == high) {
        *max = *min = arr[low];
    } else if (high == low + 1) {
        (*comparisons)++;
        if (arr[low] < arr[high]) {
            *max = arr[high];
            *min = arr[low];
        } else {
            *max = arr[low];
            *min = arr[high];
        }
    } else {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;

        dacMaxMin(arr, low, mid, &max1, &min1, comparisons);
        dacMaxMin(arr, mid + 1, high, &max2, &min2, comparisons);

        (*comparisons)++;
        *max = (max1 > max2) ? max1 : max2;

        (*comparisons)++;
        *min = (min1 < min2) ? min1 : min2;
    }
}

void generateArray(int size) {
    n = size;
    arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
    printf("Array of %d random numbers generated.\n", n);
}

void displayArray() {
    if (arr == NULL) {
        printf("Array not generated yet!\n");
        return;
    }
    printf("Array elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMAX-MIN PROBLEM MENU\n");
        printf("0. Quit\n");
        printf("1. n Random numbers => Array\n");
        printf("2. Display the Array\n");
        printf("3. Max. and Min. Values with ITERATIVE ALGORITHM\n");
        printf("4. Max. and Min. Values with DIVIDE-AND-CONQUER ALGORITHM\n");
        printf("5. Compare both in terms of element comparison\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        if (choice == 1) {
            printf("Enter n: ");
            scanf("%d", &n);
            generateArray(n);
        }
        else if (choice == 2) {
            displayArray();
        }
        else if (choice == 3) {
            if (arr == NULL) { printf("Generate array first!\n"); continue; }
            int max, min, comparisons;
            iterativeMaxMin(arr, n, &max, &min, &comparisons);
            printf("Iterative Algorithm -> Max = %d, Min = %d, Comparisons = %d\n", max, min, comparisons);
        }
        else if (choice == 4) {
            if (arr == NULL) { printf("Generate array first!\n"); continue; }
            int max, min, comparisons = 0;
            dacMaxMin(arr, 0, n - 1, &max, &min, &comparisons);
            printf("Divide & Conquer -> Max = %d, Min = %d, Comparisons = %d\n", max, min, comparisons);
        }
        else if (choice == 5) {
            if (arr == NULL) { printf("Generate array first!\n"); continue; }
            int max1, min1, comp1, max2, min2, comp2 = 0;

            iterativeMaxMin(arr, n, &max1, &min1, &comp1);
            dacMaxMin(arr, 0, n - 1, &max2, &min2, &comp2);

            printf("\n-----------------------------------------------------------\n");
            printf("Algorithm\t\tMax\tMin\tComparisons\n");
            printf("-----------------------------------------------------------\n");
            printf("Iterative\t\t%d\t%d\t%d\n", max1, min1, comp1);
            printf("Divide & Conquer\t%d\t%d\t%d\n", max2, min2, comp2);
            printf("-----------------------------------------------------------\n");
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}