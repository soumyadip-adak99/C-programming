#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node *head = NULL;

void addData(int data)
{
    node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

node *swapingPairs(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *firstNode = head;
    node *secondNode = head->next;
    firstNode->next = swapingPairs(secondNode->next);
    secondNode->next = firstNode;
    return secondNode;
}

void printLL()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main()
{

    for (int i = 1; i <= 3; i++)
    {
        addData(i);
    }

    head = swapingPairs(head);

    printLL();

    return 0;
}