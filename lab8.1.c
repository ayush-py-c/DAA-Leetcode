// Fractional Knapsack Problem
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
};

int cmp(const void *a, const void *b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return r2 > r1 ? 1 : (r2 < r1 ? -1 : 0);
}

void fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), cmp);
    double totalValue = 0.0;
    printf("Item selection (value, weight, taken):\n");
    for (int i = 0; i < n && W > 0; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
            printf("%d %d 1\n", arr[i].value, arr[i].weight);
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            printf("%d %d %.2f\n", arr[i].value, arr[i].weight, (double)W/arr[i].weight);
            W = 0;
        }
    }
    printf("Max value: %.2f\n", totalValue);
}

int main() {
    int n, W;
    printf("Enter number of items: "); scanf("%d", &n);
    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i+1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter knapsack capacity: "); scanf("%d", &W);
    fractionalKnapsack(W, arr, n);
    return 0;
}
