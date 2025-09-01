/*Write a menu (given as follows) driven program to sort a given set of elements using the 
Insertion sort method and determine the time required to sort the elements. Repeat the 
experiment for different values of n, the number of elements in the list to be sorted and 
plot a graph of the time taken versus n. The elements can be read from a file or can be 
generated using the random number generator.
INSERTION SORT MENU
0. Quit
1. n Random numbers=>Array
2. Display the Array
3. Sort the Array in Ascending Order
4. Sort the Array in Descending Order
5. Best Case Time Complexity
6. Worst Case Time Complexity
7. Average Case Time Complexity
8. Time Complexity all Cases (Best, Worst & Average) in Tabular form for values n=5000 to 50000, step=5000*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createarray(int n);
void insertionsortasc(int arr[], int n);
void insertionsortdesc(int arr[], int n);
void display(int arr[], int n);

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int* arr = createarray(n);

    int choice;
    printf("\nINSERTION SORT MENU\n");
    printf("0. Quit\n1. n Random numbers => Array\n2. Display the Array\n3. Sort the Array in Ascending Order\n");
    printf("4. Sort the Array in Descending Order\n5. Best Case Time Complexity\n6. Worst Case Time Complexity\n");
    printf("7. Average Case Time Complexity\n8. Time Complexity all Cases (Best, Worst & Average) in Tabular form for values n=5000 to 50000, step=5000\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program...\n");
                free(arr);
                exit(0);

            case 1:
                for (int i = 0; i < n; i++)
                    arr[i] = rand() % 100;
                printf("Array filled with %d random numbers.\n", n);
                break;

            case 2:
                display(arr, n);
                break;

            case 3: {
                clock_t start = clock();
                insertionsortasc(arr, n);
                clock_t end = clock();
                printf("Array sorted in Ascending Order.\n");
                printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }

            case 4: {
                clock_t start = clock();
                insertionsortdesc(arr, n);
                clock_t end = clock();
                printf("Array sorted in Descending Order.\n");
                printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }

            case 5: {
                insertionsortasc(arr, n); // Sorted array
                clock_t start = clock();
                insertionsortasc(arr, n);
                clock_t end = clock();
                printf("Best Case Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }

            case 6: {
                insertionsortasc(arr, n); // Ascending
                insertionsortdesc(arr, n); // Now descending
                clock_t start = clock();
                insertionsortasc(arr, n); // Worst-case (descending input)
                clock_t end = clock();
                printf("Worst Case Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }

            case 7: {
                for (int i = 0; i < n; i++)
                    arr[i] = rand();
                clock_t start = clock();
                insertionsortasc(arr, n);
                clock_t end = clock();
                printf("Average Case Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
                break;
            }

            case 8: {
                printf("Sl\t n\t Best(s)\t Worst(s)\t Average(s)\n");
                int x = 1;
                for (int size = 5000; size <= 50000; size += 5000) {
                    int* temp = createarray(size);
                    double best, worst, average;

                    // Best case
                    insertionsortasc(temp, size);
                    clock_t start = clock();
                    insertionsortasc(temp, size);
                    clock_t end = clock();
                    best = (double)(end - start) / CLOCKS_PER_SEC;

                    // Worst case
                    insertionsortdesc(temp, size);
                    start = clock();
                    insertionsortasc(temp, size);
                    end = clock();
                    worst = (double)(end - start) / CLOCKS_PER_SEC;

                    // Average case
                    for (int i = 0; i < size; i++)
                        temp[i] = rand();
                    start = clock();
                    insertionsortasc(temp, size);
                    end = clock();
                    average = (double)(end - start) / CLOCKS_PER_SEC;

                    printf("%d\t%d\t%.6lf\t%.6lf\t%.6lf\n", x++, size, best, worst, average);
                    free(temp);
                }
                break;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    free(arr);
    return 0;
}

int* createarray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    return arr;
}

void insertionsortasc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void insertionsortdesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}