#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int arr[MAX], n = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandom(int size) {
    n = size;
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
    printf("%d random numbers generated.\n", n);
}

void display() {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int extractMax() {
    if (n <= 0) return -1;
    int max = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapify(arr, n, 0);
    return max;
}

void insert(int val) {
    n++;
    int i = n - 1;
    arr[i] = val;
    while (i != 0 && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteNode(int idx) {
    if (idx >= n) return;
    arr[idx] = arr[n-1];
    n--;
    heapify(arr, n, idx);
}

void replaceNode(int idx, int val) {
    if (idx >= n) return;
    arr[idx] = val;
    heapify(arr, n, idx);
}

double timeSort(int arr[], int n) {
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    return ((double)(end - start))/CLOCKS_PER_SEC;
}

void analysis() {
    printf("\nAnalysis of Max-Heap Sort Algorithm\n");
    printf("Sl.No.\tValue of n\tAscending\tDescending\tRandom\n");
    for (int size = 5000, k=1; size <= 50000; size += 5000, k++) {
        int *asc = (int*)malloc(size*sizeof(int));
        int *desc = (int*)malloc(size*sizeof(int));
        int *rnd = (int*)malloc(size*sizeof(int));
        for (int i = 0; i < size; i++) {
            asc[i] = i;
            desc[i] = size-i;
            rnd[i] = rand() % 10000;
        }
        double t1 = timeSort(asc, size);
        double t2 = timeSort(desc, size);
        double t3 = timeSort(rnd, size);
        printf("%d\t%d\t\t%lf\t%lf\t%lf\n", k, size, t1, t2, t3);
        free(asc); free(desc); free(rnd);
    }
}

int main() {
    int choice, val, idx;
    while (1) {
        printf("\nMAX-HEAP & PRIORITY QUEUE MENU\n");
        printf("0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n");
        printf("3. Sort Ascending (Heap Sort)\n4. Sort Descending (any algo)\n");
        printf("5. Time Complexity on Random Data\n");
        printf("6. Time Complexity on Ascending Data\n");
        printf("7. Time Complexity on Descending Data\n");
        printf("8. Tabular Analysis\n9. Extract largest element\n");
        printf("10. Replace value at node\n11. Insert new element\n12. Delete element\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 0: exit(0);
            case 1: {
                int size;
                printf("Enter n: "); scanf("%d", &size);
                generateRandom(size); break;
            }
            case 2: display(); break;
            case 3: heapSort(arr, n); printf("Sorted Ascending.\n"); break;
            case 4: {
                for (int i=0;i<n-1;i++)
                    for (int j=0;j<n-i-1;j++)
                        if (arr[j] < arr[j+1])
                            swap(&arr[j], &arr[j+1]);
                printf("Sorted Descending.\n"); break;
            }
            case 5: {
                int *tmp = (int*)malloc(n*sizeof(int));
                for (int i=0;i<n;i++) tmp[i]=rand()%10000;
                printf("Time: %lf sec\n", timeSort(tmp, n));
                free(tmp); break;
            }
            case 6: {
                int *tmp = (int*)malloc(n*sizeof(int));
                for (int i=0;i<n;i++) tmp[i]=i;
                printf("Time: %lf sec\n", timeSort(tmp, n));
                free(tmp); break;
            }
            case 7: {
                int *tmp = (int*)malloc(n*sizeof(int));
                for (int i=0;i<n;i++) tmp[i]=n-i;
                printf("Time: %lf sec\n", timeSort(tmp, n));
                free(tmp); break;
            }
            case 8: analysis(); break;
            case 9: printf("Largest: %d\n", extractMax()); break;
            case 10: printf("Enter index and new value: "); scanf("%d%d",&idx,&val); replaceNode(idx,val); break;
            case 11: printf("Enter value: "); scanf("%d",&val); insert(val); break;
            case 12: printf("Enter index: "); scanf("%d",&idx); deleteNode(idx); break;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}