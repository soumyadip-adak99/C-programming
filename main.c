#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int size = 0;

// Create a node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    size++;
}

void insertEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        size++;
        return;
    }

    struct Node *currentNode = head;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;

    currentNode->next = newNode;
    size++;
}

void insertAfter(int key, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        printf("Key is not present in list. KEY = %d\n", key);
        return;
    }

    struct Node *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            size++;
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Key is not present in list. KEY = %d\n", key);
}

void insertAtPos(int pos, int data) {
    struct Node *newNode = createNode(data);
    
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertFront(data);
        return;
    }

    struct Node *currentNode = head;
    for (int i = 1; i < pos - 1; i++)
        currentNode = currentNode->next;

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    size++;
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    size--;
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        size--;
        return;
    }

    struct Node *secondLastNode = head;
    struct Node *lastNode = head->next;
    while (lastNode->next != NULL) {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }
    secondLastNode->next = NULL;
    free(lastNode);
    size--;
}

void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        size--;
        return;
    }

    struct Node *prevNode = head;
    struct Node *currentNode = head->next;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            prevNode->next = currentNode->next;
            free(currentNode);
            size--;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Key not found: KEY = %d\n", key);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d->", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int getSize() {
    return size;
}

int main() {
    int choice, key, data, pos;

    while (true) {
        printf("\n========== MENU ==========\n");
        printf("1. Attach coach x at the very front.\n");
        printf("2. Couple coach x at the rear.\n");
        printf("3. Insert coach x immediately after coach key.\n");
        printf("4. Insert coach x at position pos (front = 1).\n");
        printf("5. Detach the front coach.\n");
        printf("6. Detach the rear coach.\n");
        printf("7. Detach the coach whose number is key.\n");
        printf("8. Get the size of the train.\n");
        printf("9. Print the whole train from engine to rear.\n");
        printf("10. End the program.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a coach number: ");
            scanf("%d", &data);
            insertFront(data);
            break;
        case 2:
            printf("Enter a coach number: ");
            scanf("%d", &data);
            insertEnd(data);
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter a coach number: ");
            scanf("%d", &data);
            insertAfter(key, data);
            break;
        case 4:
            printf("Enter a position: ");
            scanf("%d", &pos);
            printf("Enter a coach number: ");
            scanf("%d", &data);
            insertAtPos(pos, data);
            break;
        case 5:
            deleteFront();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("Enter a coach number to remove: ");
            scanf("%d", &key);
            deleteByValue(key);
            break;
        case 8:
            printf("Size of the train = %d\n", getSize());
            break;
        case 9:
            display();
            break;
        case 10:
            printf("Program ended.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}