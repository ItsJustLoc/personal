/*
Coding Assignement 1
Name: Loc Nguyen
ID: 1001884595
Date: June 14, 2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct node
{
    int number;
    struct node *next_ptr;
}
NODE;

void AddNodeToLL(int Number, NODE **LinkedListHead)
{
    NODE *temp = malloc(sizeof(NODE));

    temp->number = Number;
    temp->next_ptr = NULL;

    if (*LinkedListHead == NULL)
        *LinkedListHead = temp;

    else
    {
        NODE *current = *LinkedListHead;
    
        while (current->next_ptr != NULL)
        {
            current = current->next_ptr;
        }

        current->next_ptr = temp;
    }
}

void ReadFileIntoLL(int argc, char *argv[], NODE **LLH)
{
    int aNum, total = 0, counter = 0;
    char mode[] = "r";
    char filename[20];
    char buffer[500];
    char *token;

    strcpy(filename, *argv);

    FILE *fp = fopen(filename, mode);

    if (!fp)
        printf("File must be provided on command line...exiting\n");

    while (fgets(buffer, sizeof(buffer), fp))
    {
        token = strtok(buffer, "\n");
        aNum = atoi(token);

        AddNodeToLL(aNum, LLH);
        
        total += aNum;
        counter += 1;
    }

    printf("%d records were read for a total sum of %d\n", counter, total);
    fclose(fp);
}

void PrintLL(NODE *LLH)
{
    int total = 0, counter = 0;
    NODE *TempPtr;

    TempPtr = LLH;

    while (TempPtr != NULL)
    {
        #ifdef PRINT
            printf("\n%p %d %p\n", TempPtr, TempPtr->number, TempPtr->next_ptr);
        #endif

        total += TempPtr->number;
        counter += 1;

        TempPtr = TempPtr->next_ptr;
    }

    printf("\n%d nodes were deleted for a total sum of %d\n", counter, total);
}

void FreeLL(NODE **LLH)
{
    int total = 0, counter = 0; 
    NODE* TempPtr;
    NODE* last_visited = NULL;
    TempPtr = *LLH;

    while (TempPtr)
    {
        if(last_visited)
        {
            free(last_visited);
        }

        #ifdef PRINT
            printf("\nFreeing %p %d %p\n", TempPtr, TempPtr->number, TempPtr->next_ptr);
        #endif

        total += TempPtr->number;
        counter += 1;

        last_visited = TempPtr;
        TempPtr = TempPtr->next_ptr;
    }

    printf("\n%d nodes were deleted for a total sum of %d\n", counter, total);
    free(TempPtr);
}

int main(int argc, char *argv[])
{
    NODE *LLH = NULL;
    clock_t start, end;

    start = clock();
    ReadFileIntoLL(argc, &argv[1], &LLH);
    end = clock();
    printf("\n%ld tics to write the file into the linked list\n", end-start);

    #ifdef PRINT
        start = clock();
        PrintLL(LLH);
        end = clock();
        printf("\n%ld tics to print the linked list\n", end-start);
    #endif

    start = clock();
    FreeLL(&LLH);
    end = clock();
    printf("\n%ld tics to free the linked list\n", end-start);

    return 0;
}