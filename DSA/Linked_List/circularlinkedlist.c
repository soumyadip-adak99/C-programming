#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// use typedef insted of use multiple times struct Node -> only write Node
typedef struct Node Node;

Node *head = NULL;
Node *tail = NULL;

struct Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head;
}

void insertRear(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void deleteFront() {
    if (head = NULL) {
        printf("List is empty.\n");
        return;
    }

    if(head == tail) {
        head = NULL;
        tail = NULL;
        return;
    }

    head = head->next;
    tail->next = head;
}

void deleteRear() {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if(head == tail) {
        head = NULL;
        tail = NULL;
        return;
    }

    Node *currentNode = head;
    while(currentNode->next != tail) {
        currentNode = currentNode->next;
    }
    tail = currentNode;
    tail->next = head;
}



