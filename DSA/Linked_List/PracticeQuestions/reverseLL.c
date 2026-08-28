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

void addItems(int data)
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

void reverseLL()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *prevNode = head;
    node *currentNode = head->next;

    while (currentNode != NULL)
    {
        node *nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head->next = NULL;
    head = prevNode;
}

node *reverseLLrecursion(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newHode = reverseLLrecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHode;
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
        printf("%d ->", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main()
{

    addItems(10);
    addItems(20);
    addItems(30);
    addItems(40);
    printf("Order->\n");
    printLL();
    // printf("Recursion->\n");
    // head = reverseLLrecursion(head);
    // printLL();
    printf("Using iterator-> \n");
    reverseLL();
    printLL();
    return 0;
}