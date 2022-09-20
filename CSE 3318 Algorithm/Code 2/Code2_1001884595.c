/*
Coding Assignement 1
Name: Loc Nguyen
ID: 1001884595
Date: June 21, 2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void insertionSort (int v[], int s) 
{
    int i, j, value;

    for (i = 1; i < s; i++)
    {
        value = v[i];
        j = i - 1;

        while ((j >= 0) && (value < v[j]))
        {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = value;
    }
}

void PrintArray(int ArrayToPrint[], int SizeAP)
{
    int i;

    for (i = 0; i < SizeAP; i+=1)
        printf("%d\n", ArrayToPrint[i]);
}

int ReadFileIntoArray(int argc, char *argv[], int **AP)
{
    int i = 0, counter = 0;
    char FileLine[500];
    char filename[20], mode[] = "r";

    strcpy(filename, *argv);

    FILE *fp = fopen(filename, mode);

    if (!fp)
    {
        printf("File must be provided on command line...exiting\n");
        exit(0);
    }

    while (fgets(FileLine, sizeof(FileLine), fp))
    {
        counter += 1;
    }
    
    fseek(fp, 0, SEEK_SET);
        
    *AP = malloc(counter * sizeof(int));

    while (fgets(FileLine, sizeof(FileLine), fp))
    {
        (*AP)[i] = atoi(FileLine);
        i += 1;
    }

    fclose(fp);
    return counter;
}

int main(int argc, char *argv[])
{
    int *AP = NULL;
    int elements;
    clock_t start, end;

    elements = ReadFileIntoArray(argc, &argv[1], &AP);

    #ifdef PRINTARRAY
        PrintArray(AP, elements);
    #endif

    start = clock();
    insertionSort(AP, elements);
    end = clock();

    #ifdef PRINTARRAY
        printf("\n\n");
        PrintArray(AP, elements);
        printf("\n\nProcessed %d records\n", elements);
        printf("Insertion Sort Tics = %lu\n", end-start);
    #else
        printf("Insertion Sort = %lu Tics\n", end-start);
    #endif

    free(AP);
    return 0;
}
