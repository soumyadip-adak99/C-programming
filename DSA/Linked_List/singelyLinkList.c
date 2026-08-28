#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Linklist
{
    node *head;
    int size;
} list;

void initList(list *list)
{
    list->head = NULL;
    list->size = 0;
}

void addFirst(list *list, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void addLast(list *list, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        node *currentNode = list->head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    list->size++;
}

void deleteFirst(list *list)
{
    if (list->head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void deleteLast(list *list)
{
    if (list->head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
    }
    else
    {
        node *secondLastNode = list->head;
        node *lastNode = list->head->next;

        while (lastNode->next != NULL)
        {
            secondLastNode = lastNode;
            lastNode = lastNode->next;
        }

        secondLastNode->next = NULL;
        free(lastNode);
    }
    list->size--;
}

void printList(list *list)
{
    if (list->head == NULL)
    {
        printf("This list is empty.\n");
        return;
    }

    node *currentNode = list->head;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int getSize(list *list)
{
    return list->size;
}

int main()
{
    list a;
    initList(&a);

    /* addFirst(&a, 10);
     addFirst(&a, 20);
     addFirst(&a, 30);
     addFirst(&a, 60);
     addFirst(&a, 50);*/

    addLast(&a, 10);
    addLast(&a, 20);
    addLast(&a, 40);
    addLast(&a, 50);
    addLast(&a, 70);
    addLast(&a, 90);

    deleteLast(&a);

    printf("Size: %d\n", getSize(&a));

    printList(&a);

    return 0;
}
