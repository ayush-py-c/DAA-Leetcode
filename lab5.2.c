#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortAsc(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortAsc(arr, l, m);
        mergeSortAsc(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortDesc(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortDesc(arr, l, m);
        mergeSortDesc(arr, m + 1, r);
        // Merge for descending order
        int n1 = m - l + 1, n2 = r - m;
        int *L = malloc(n1 * sizeof(int));
        int *R = malloc(n2 * sizeof(int));

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        free(L);
        free(R);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void timeAnalysis(int n, int arr[]) {
    int *temp = malloc(n * sizeof(int));
    clock_t start, end;
    double bestTime, worstTime, avgTime;

    // Best case: sorted array
    for (int i = 0; i < n; i++) arr[i] = i;
    copyArray(temp, arr, n);
    start = clock();
    mergeSortAsc(temp, 0, n - 1);
    end = clock();
    bestTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Worst case: reverse sorted array
    for (int i = 0; i < n; i++) arr[i] = n - i;
    copyArray(temp, arr, n);
    start = clock();
    mergeSortAsc(temp, 0, n - 1);
    end = clock();
    worstTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Average case: average over 3 random runs
    avgTime = 0;
    for (int i = 0; i < 3; i++) {
        generateRandom(arr, n);
        copyArray(temp, arr, n);
        start = clock();
        mergeSortAsc(temp, 0, n - 1);
        end = clock();
        avgTime += (double)(end - start) / CLOCKS_PER_SEC;
    }
    avgTime /= 3;

    printf("%8d | %12lf | %13lf | %13lf\n", n, bestTime, worstTime, avgTime);
    free(temp);
}

int main() {
    int choice, n = 0;
    int *arr = NULL;

    srand(time(NULL));

    while (1) {
        printf("\nMERGE SORT MENU\n");
        printf("0. Quit\n");
        printf("1. n Random numbers => Array\n");
        printf("2. Display the Array\n");
        printf("3. Sort the Array in Ascending Order\n");
        printf("4. Sort the Array in Descending Order\n");
        printf("5. Best Case Time Complexity\n");
        printf("6. Worst Case Time Complexity\n");
        printf("7. Average Case Time Complexity\n");
        printf("8. Time Complexity all Cases in Tabular form (n=5000 to 50000)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Enter number of elements (n): ");
                scanf("%d", &n);
                if (arr) free(arr);
                arr = malloc(n * sizeof(int));
                generateRandom(arr, n);
                printf("Array generated.\n");
                break;
            case 2:
                if (arr && n > 0) display(arr, n);
                else printf("No array found. Generate first.\n");
                break;
            case 3:
                if (arr && n > 0) {
                    mergeSortAsc(arr, 0, n - 1);
                    printf("Array sorted in ascending order.\n");
                } else {
                    printf("No array found.\n");
                }
                break;
            case 4:
                if (arr && n > 0) {
                    mergeSortDesc(arr, 0, n - 1);
                    printf("Array sorted in descending order.\n");
                } else {
                    printf("No array found.\n");
                }
                break;
            case 5:
                if (n > 0) {
                    for (int i = 0; i < n; i++) arr[i] = i;
                    clock_t start = clock();
                    mergeSortAsc(arr, 0, n - 1);
                    clock_t end = clock();
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Best Case Time for n=%d: %lf seconds\n", n, time_taken);
                } else {
                    printf("Generate array first.\n");
                }
                break;
            case 6:
                if (n > 0) {
                    for (int i = 0; i < n; i++) arr[i] = n - i;
                    clock_t start = clock();
                    mergeSortAsc(arr, 0, n - 1);
                    clock_t end = clock();
                    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Worst Case Time for n=%d: %lf seconds\n", n, time_taken);
                } else {
                    printf("Generate array first.\n");
                }
                break;
            case 7:
                if (n > 0) {
                    double avgTime = 0;
                    for (int i = 0; i < 3; i++) {
                        generateRandom(arr, n);
                        clock_t start = clock();
                        mergeSortAsc(arr, 0, n - 1);
                        clock_t end = clock();
                        avgTime += (double)(end - start) / CLOCKS_PER_SEC;
                    }
                    avgTime /= 3;
                    printf("Average Case Time for n=%d: %lf seconds\n", n, avgTime);
                } else {
                    printf("Generate array first.\n");
                }
                break;
            case 8:
                if (arr) free(arr);
                printf("\nAnalysis of Merge Sort Algorithm\n");
                printf("   n   |  Best Case Time | Worst Case Time | Average Case Time\n");
                printf("------------------------------------------------------------\n");
                for (int size = 5000; size <= 50000; size += 5000) {
                    arr = malloc(size * sizeof(int));
                    timeAnalysis(size, arr);
                    free(arr);
                }
                printf("------------------------------------------------------------\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    if(arr) free(arr);
    return 0;
}