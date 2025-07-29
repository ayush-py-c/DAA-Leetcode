// 4.2. Write a menu (given as follows) driven program to sort a given set of elements using the 
// Insertion sort method and determine the time required to sort the elements. Repeat the 
// experiment for different values of n, the number of elements in the list to be sorted and 
// plot a graph of the time taken versus n. The elements can be read from a file or can be 
// generated using the random number generator.
// INSERTION SORT MENU
// 0. Quit
// 1. n Random numbers=>Array
// 2. Display the Array
// 3. Sort the Array in Ascending Order
// 4. Sort the Array in Descending Order
// 5. Best Case Time Complexity
// 6. Worst Case Time Complexity
// 7. Average Case Time Complexity
// 8. Time Complexity all Cases (Best, 
// Worst & Average) in Tabular form for 
// values n=5000 to 50000, step=5000
// Enter your choice:
// If the choice is option 8, then it will display the tabular form as follows:


#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX_SIZE 100000
int arr[MAX_SIZE];
int n = 0;
void quit() {
    printf("Exiting the program.\n");
    exit(0);
}
void nrandomArray(){
    printf("Enter n: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) n = MAX_SIZE;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {

        arr[i] = rand() % 100; 
    }
    printf("Random array generated.\n");

}
void displayArray(){
    printf("Current array elements are: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}
void randomno(){
    printf("Generating random numbers...\n");
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
    printf("Random numbers generated.\n");
}
void bestCaseTimeComplexity() {
    printf("Best Case Time Complexity: O(n)\n");
    // int res = rand() % 100; // Simulating best case
    // printf("Best Case Time Complexity: O(n) (simulated result: %d) \n", res);
    // for(int i = 5000; i <= 50000; i += 5000) {
    //     printf("%d\tO(n)\n", i);
    // }
}
void worstCaseTimeComplexity() {
    printf("Worst Case Time Complexity: O(n^2)\n");
}
void averageCaseTimeComplexity() {
    printf("Average Case Time Complexity: O(n^2)\n");
}

void timeComplexityTable() {
    printf("Time Complexity Table:\n");
    printf("n\tBest Case\tWorst Case\tAverage Case\n");
    for (int i = 5000; i <= 50000; i += 5000) {
        printf("%d\tO(n)\t\tO(n^2)\t\tO(n^2)\n", i);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nINSERTION SORT MENU\n");
        printf("0. Quit\n");
        printf("1. n Random numbers => Array\n");
        printf("2. Display the Array\n");
        printf("3. Sort the Array in Ascending Order\n");
        printf("4. Sort the Array in Descending Order\n");
        printf("5. Best Case Time Complexity\n");
        printf("6. Worst Case Time Complexity\n");
        printf("7. Average Case Time Complexity\n");
        printf("8. Time Complexity all Cases (Best, Worst & Average) in Tabular form for values n=5000 to 50000, step=5000\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                quit();
                break;
            case 1:
                nrandomArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                insertionSortAscending(arr, n);
                printf("Array sorted in ascending order.\n");
                break;
            case 4:
                insertionSortDescending(arr, n);
                printf("Array sorted in descending order.\n");
                break;
            case 5:
                bestCaseTimeComplexity();
                break;
            case 6:
                worstCaseTimeComplexity();
                break;
            case 7:
                averageCaseTimeComplexity();
                break;
            case 8:
                timeComplexityTable();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}