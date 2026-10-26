#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addFirst(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void addBefore(int data, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *newNode = createNode(data);
    if (head->data == key) {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *currentNode = head;

    while (currentNode != NULL && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }

    Node *prevNode = currentNode->prev;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    newNode->next = currentNode;
    currentNode->prev = newNode;
}

void addAfter(int data, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;

    while (currentNode != NULL && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }

    Node *newNode = createNode(data);
    Node *nextNode = currentNode->next;

    currentNode->next = newNode;
    newNode->prev = currentNode;

    newNode->next = nextNode;

    if (nextNode != NULL)
        nextNode->prev = newNode;
}

void addLast(int data) {
    Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        Node *currentNode = head;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("NULL->");

        Node *currentNode = head;
        while (currentNode != NULL) {
            printf("%d->", currentNode->data);
            printf("<-");
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

void main() {
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);

    addAfter(1, 30);
    addBefore(5, 30);
    display();
}