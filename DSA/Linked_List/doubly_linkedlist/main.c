#include <stdio.h>
#include <stdlib.h>
#define null ((void *)0)

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node *head = null;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == null) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    newNode->data = data;
    newNode->prev = null;
    newNode->next = null;
    return newNode;
}

void addFirst(int data) {
    Node *newNode = createNode(data);

    if (head == null) {
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void addBefore(int data, int key) {
    if (head == null) {
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

    while (currentNode != null && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == null) {
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
    if (head == null) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;

    while (currentNode != null && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == null) {
        printf("Key %d not found.\n", key);
        return;
    }

    Node *newNode = createNode(data);
    Node *nextNode = currentNode->next;

    currentNode->next = newNode;
    newNode->prev = currentNode;

    newNode->next = nextNode;

    if (nextNode != null)
        nextNode->prev = newNode;
}

void addLast(int data) {
    Node *newNode = createNode(data);

    if (head == null) {
        head = newNode;
    } else {
        Node *currentNode = head;
        while (currentNode->next != null)
            currentNode = currentNode->next;

        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
}

void deleteFirst() {
    if (head == null) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;

    head = head->next;
    if (head != null)
        head->prev = null;
}

void deleteEnd() {
    if (head == null) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == null) {
        free(head);
        head = null;
        return;
    }

    Node *currentNode = head;
    while (currentNode->next != null)
        currentNode = currentNode->next;

    currentNode->prev->next = null;
    free(currentNode);
}

void deleteAfter(int key) {
    if (head == null) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;
    while (currentNode != null && currentNode->data != key)
        currentNode = currentNode->next;

    // if the key is not found
    if (currentNode == null) {
        printf("Key %d not found.\n", key);
        return;
    }

    // if key is last node
    if (currentNode->next == null) {
        printf("Delete not possible because (key->next_node == null)\n");
        return;
    }

    Node *temp = currentNode->next;
    currentNode->next = temp->next;

    if (temp->next != null)
        temp->next->prev = currentNode;

    free(temp);
}

void display() {
    if (head == null) {
        printf("List is empty.\n");
    } else {
        printf("NULL->");

        Node *currentNode = head;
        while (currentNode != null) {
            printf("%d->", currentNode->data);
            printf("<-");
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

void deleteList() {
    if (head == null) {
        printf("List is empty.\n");
        return;
    }

    Node *currentNode = head;
    while (currentNode != null) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    head = null;
}

void main() {
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);

    display();

    printf("\n\n");
    printf("If the key is 40\n\n");
    deleteAfter(40);
    display();
}