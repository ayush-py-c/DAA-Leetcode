#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void generateSorted(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
}

void generateReverse(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

double measureTime(void (*generator)(int[], int), int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    generator(arr, n);

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    free(arr);
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(0));
    int choice, n, *arr;
    clock_t start, end;
    double time_taken;

    while (1) {
        printf("\n--- Quick Sort Menu ---\n");
        printf("1. Sort Already Sorted Data\n");
        printf("2. Sort Reverse Sorted Data\n");
        printf("3. Sort Random Data\n");
        printf("4. Generate Performance Table (Time vs n)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice >= 1 && choice <= 3) {
            printf("Enter number of elements (n): ");
            scanf("%d", &n);
            arr = (int *)malloc(n * sizeof(int));

            if (choice == 1) generateSorted(arr, n);
            else if (choice == 2) generateReverse(arr, n);
            else generateRandom(arr, n);

            printf("\nOriginal Array:\n");
            printArray(arr, n);

            start = clock();
            quickSort(arr, 0, n - 1);
            end = clock();

            printf("\nSorted Array:\n");
            printArray(arr, n);

            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("\nTime taken to sort %d elements = %f seconds\n", n, time_taken);

            free(arr);
        }
        else if (choice == 4) {
            int sizes[] = {1000, 5000, 10000, 20000, 30000};
            int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

            printf("\n----------------------------------------------------------------------------------\n");
            printf("   n\t   Sorted (sec)\t   Reverse (sec)\t   Random (sec)\n");
            printf("----------------------------------------------------------------------------------\n");

            for (int i = 0; i < num_sizes; i++) {
                n = sizes[i];
                double t_sorted = measureTime(generateSorted, n);
                double t_reverse = measureTime(generateReverse, n);
                double t_random = measureTime(generateRandom, n);

                printf("%6d\t%12f\t%15f\t%13f\n", n, t_sorted, t_reverse, t_random);
            }
            printf("----------------------------------------------------------------------------------\n");
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}