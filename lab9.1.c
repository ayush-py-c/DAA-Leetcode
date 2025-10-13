#include <stdio.h>
#include <stdlib.h>

#define MAX 10   

int adjMatrix[MAX][MAX];
int visited[MAX];        
int n;                   

void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void displayMatrix() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList() {
    int i, j;
    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++) {
        printf("%c -> ", 'A' + i); 
        for (j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1)
                printf("%c ", 'A' + j);
        }
        printf("\n");
    }
}

void BFS(int start) {
    int queue[MAX], front = -1, rear = -1;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    printf("\nBFS Traversal: ");

    while (front != rear) {
        int node = queue[++front];
        printf("%c ", 'A' + node);

        for (i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int v) {
    int i;
    visited[v] = 1;
    printf("%c ", 'A' + v);

    for (i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1 && visited[i] == 0)
            DFSUtil(i);
    }
}

void DFS(int start) {
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0; 

    printf("\nDFS Traversal: ");
    DFSUtil(start);
    printf("\n");
}

int main() {
    int choice;
    int start;

    while (1) {
        printf("\n----- Graph Operations -----\n");
        printf("0. Exit\n");
        printf("1. Input the graph\n");
        printf("2. Display adjacency matrix\n");
        printf("3. Display adjacency list\n");
        printf("4. Traverse graph using BFS\n");
        printf("5. Traverse graph using DFS\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            createGraph();
            break;
        case 2:
            displayMatrix();
            break;
        case 3:
            displayList();
            break;
        case 4:
            printf("Enter starting vertex (0 for A, 1 for B ...): ");
            scanf("%d", &start);
            BFS(start);
            break;
        case 5:
            printf("Enter starting vertex (0 for A, 1 for B ...): ");
            scanf("%d", &start);
            DFS(start);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}