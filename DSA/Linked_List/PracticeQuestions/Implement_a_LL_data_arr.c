#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int *data;
    struct Node *next;
} node;

node *createNode(int *data, int size)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        newNode->data[i] = data[i];
    }
    newNode->next = NULL;
    return newNode;
}

node *head = NULL;
int listSize = 0;

void addData(int *data, int size)
{
    node *newNode = createNode(data, size);
    if (head == NULL)
    {
        head = newNode;
        listSize++;
        return;
    }
    newNode->next = head;
    head = newNode;
    listSize++;
}

void printLL(int arraySize)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *currentNode = head;
    while (currentNode != NULL)
    {
        for (int i = 0; i < arraySize; i++)
        {
            printf("%d ", currentNode->data[i]);
        }
        printf("--> ");
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};

    int arraySize = sizeof(a) / sizeof(a[0]);

    addData(a, arraySize);
    addData(b, arraySize);
    addData(c, arraySize);

    printLL(arraySize);

    return 0;
}
