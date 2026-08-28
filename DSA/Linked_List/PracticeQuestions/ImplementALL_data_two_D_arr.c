#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int **data;
    struct Node *next;
} node;

typedef struct TwoDarr
{
    node *head;
    int row;
    int col;
    int size;
} TowDarr;

int **create2DArr(int row, int col, int data[row][col])
{
    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = data[i][j];
        }
    }
    return arr;
}

node *createNode(int row, int col, int data[row][col])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = create2DArr(row, col, data);
    newNode->next = NULL;
    return newNode;
}

TowDarr *initLinkedList(int row, int col)
{
    TowDarr *list = (TowDarr *)malloc(sizeof(TowDarr));
    list->head = NULL;
    list->row = row;
    list->col = col;
    return list;
}

void addItems(TowDarr *list, int row, int col, int data[row][col])
{
    node *newNode = createNode(row, col, data);
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }

    node *currentNode = list->head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

void printLL(TowDarr *list)
{
    if (list->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *currNode = list->head;
    while (currNode != NULL)
    {
        for (int i = 0; i < list->row; i++)
        {
            for (int j = 0; j < list->col; j++)
            {
                printf("%d ", currNode->data[i][j]);
            }
            printf("\n");
        }
        printf("->\n");
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main()
{
    TowDarr *list = initLinkedList(3, 3);

    int row, col;
    row = col = 3;

    int a[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int b[3][3] = {{20, 10, 30}, {50, 40, 60}, {80, 70, 90}};
    int c[3][3] = {{30, 20, 10}, {60, 50, 40}, {90, 80, 70}};

    // Function calls ->
    addItems(list, row, col, a);
    addItems(list, row, col, b);
    addItems(list, row, col, c);

    printLL(list);

    return 0;
}