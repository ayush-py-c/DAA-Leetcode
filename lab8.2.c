// Job Scheduling with Deadline Problem
#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int profit;
    int deadline;
};

int cmp(const void *a, const void *b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

void jobScheduling(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), cmp);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) slot[i] = -1;
    int totalProfit = 0;
    printf("Job selection (id, profit, deadline):\n");
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline-1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                printf("%d %d %d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
                break;
            }
        }
    }
    printf("Max profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter number of jobs: "); scanf("%d", &n);
    struct Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter id, profit, deadline for job %d: ", i+1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }
    jobScheduling(jobs, n);
    return 0;
}
