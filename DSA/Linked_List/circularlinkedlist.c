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
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

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

    if (head == tail) {
        head = NULL;
        tail = NULL;
        return;
    }

    head = head->next;
    tail->next = head;
}

void deleteRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head == tail) {
        head = NULL;
        tail = NULL;
        return;
    }

    Node *currentNode = head;
    while (currentNode->next != tail) {
        currentNode = currentNode->next;
    }
    tail = currentNode;
    tail->next = head;
}

void deleteByValue(int val) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;

    do {
        if (currentNode->data == val) {
            Node *deleteNode = currentNode->next;

            // only one node
            if (deleteNode == currentNode) {
                head = NULL;
                tail = NULL;
                free(deleteNode);
                return;
            }

            // deleting tail
            if (deleteNode == tail) {
                tail = currentNode;
            }

            currentNode->next = deleteNode->next;

            tail->next = head;

            free(deleteNode);
            return;
        }

        currentNode = currentNode->next;
    } while (currentNode != head);

    printf("Node %d not found.\n", val);
}

void deleteList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;
    Node *nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(tail);

    head = NULL;
    tail = NULL;

    printf("Circular linked list deleted.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;
    do {
        printf("%d->", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);
    
    printf("head\n");
}

int main() {
    insertFront(20);
    insertFront(30);
    insertFront(40);
    insertRear(50);
    insertRear(60);
    display();
    return 0;
}