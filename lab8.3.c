// Huffman Coding Menu Driven Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* newNode(char ch, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void preorder(struct Node* root) {
    if (!root) return;
    if (root->ch) printf("%c ", root->ch);
    preorder(root->left);
    preorder(root->right);
}

void printCodes(struct Node* root, char* code, int depth) {
    if (!root) return;
    if (root->ch) {
        code[depth] = '\0';
        printf("%c: %s\n", root->ch, code);
    }
    if (root->left) {
        code[depth] = '0';
        printCodes(root->left, code, depth+1);
    }
    if (root->right) {
        code[depth] = '1';
        printCodes(root->right, code, depth+1);
    }
}

struct Node* buildHuffman(char chars[], int freq[], int n) {
    struct Node* nodes[MAX];
    for (int i = 0; i < n; i++) nodes[i] = newNode(chars[i], freq[i]);
    int size = n;
    while (size > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min2]->freq < nodes[min1]->freq) {
            int t = min1; min1 = min2; min2 = t;
        }
        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) { min2 = min1; min1 = i; }
            else if (nodes[i]->freq < nodes[min2]->freq) min2 = i;
        }
        struct Node* merged = newNode(0, nodes[min1]->freq + nodes[min2]->freq);
        merged->left = nodes[min1]; merged->right = nodes[min2];
        nodes[min1] = merged;
        for (int i = min2; i < size-1; i++) nodes[i] = nodes[i+1];
        size--;
    }
    return nodes[0];
}

int main() {
    int n, choice;
    char chars[MAX];
    int freq[MAX];
    struct Node* root = NULL;
    while (1) {
        printf("\nHUFFMAN CODE GENERATION MENU\n");
        printf("0. Quit\n1. Input n unique characters with their frequencies into an array\n2. Display the Array\n3. Generate Huffman Tree and Traverse the tree with pre-order.\n4. Generate Huffman Codes for n characters and display the same.\n5. Compare Huffman code with Fixed-Length Code\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0: exit(0);
            case 1:
                printf("Enter n: "); scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter character and frequency: ");
                    scanf(" %c %d", &chars[i], &freq[i]);
                }
                break;
            case 2:
                printf("Characters and frequencies:\n");
                for (int i = 0; i < n; i++) printf("%c: %d\n", chars[i], freq[i]);
                break;
            case 3:
                root = buildHuffman(chars, freq, n);
                printf("Pre-order traversal: ");
                preorder(root); printf("\n");
                break;
            case 4:
                if (!root) root = buildHuffman(chars, freq, n);
                printf("Huffman Codes:\n");
                char code[MAX];
                printCodes(root, code, 0);
                break;
            case 5:
                printf("Fixed length code: %d bits\n", (int)ceil(log2(n)));
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
