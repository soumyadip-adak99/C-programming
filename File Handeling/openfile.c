#include <stdio.h>
#include <stdlib.h>

void main() {

    FILE *file;

    // r -> is mode r for read the file 
    file = fopen("text.txt", "r");

    if (file == NULL) 
        printf("File not found\n");
    else 
        printf("File is opend\n");
}