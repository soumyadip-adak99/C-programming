#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;
int size = 0;

int getSize() {
    return size;
}

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBegining(int data) {
    Node *newNode = createNode(data);
}