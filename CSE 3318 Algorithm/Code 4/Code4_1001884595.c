/*
Coding Assignement 3
Name: Loc Nguyen
ID: 1001884595
Date: June 30, 2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void swap(int *SwapA, int *SwapB)
{
    int temp = *SwapA;
    *SwapA = *SwapB;
    *SwapB = temp;
}

int partition(int A[], int low, int high)
{
    int i, j = 0;
    #if QSM
        int middle = (high+low)/2;
        swap(&A[middle], &A[high]);
    #elif QSRND
        int random = ((rand() % (high-low+1)) + low);
        swap(&A[random], &A[high]);
    #endif
    int pivot = A[high];

    i = (low - 1);

    for (j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);

    return (i + 1);
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int ndx = partition(A, low, high);

        QuickSort(A, low, ndx - 1);
        QuickSort(A, ndx + 1, high);
    }
}

void PrintArray(int ArrayToPrint[], int SizeAP)
{
    int i;

    for (i = 0; i < SizeAP; i+=1)
        printf("%d\n", ArrayToPrint[i]);

    printf("\n\n");
}

int ReadFileIntoArray(int argc, char *argv[], int **AP)
{
    int i = 0, counter = 0;
    char FileLine[500];
    char filename[20], mode[] = "r";


    FILE *fp = NULL;

    if (argc > 1)
    {
        strcpy(filename, argv[1]);
        fp = fopen(filename, mode);
        
        if (!fp)
        {
            printf("File must be provided on command line...exiting\n");
            exit(0);
        }
    }
    else
    {
        printf("Exiting... Not enough command line parameters");
        exit(0);
    }

    while (fgets(FileLine, sizeof(FileLine)-1, fp))
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
    int elements, i, loop = 0;
    unsigned long quickSortTime = 0;
    clock_t start, end;

    if (argc > 2)
    {
        loop = atoi(argv[2]);
        
        for (i = 0; i < loop; i++)
        {
            elements = ReadFileIntoArray(argc, argv, &AP);

            #ifdef PRINTARRAY
                PrintArray(AP, elements);
            #endif

            free(AP);

            elements = ReadFileIntoArray(argc, argv, &AP);
            
            start = clock();
            QuickSort(AP, 0, elements-1);
            end = clock();

            printf("Run %d complete : %lu tics\n", i+1, end-start);

            quickSortTime += (end - start);

            #ifdef PRINTARRAY
                PrintArray(AP, elements);
            #endif

            free(AP);
        }

        quickSortTime = quickSortTime / loop;
    }
    else
    {
        printf("Number of runs not specified on command line...defaulting to 10\n");
        loop = 10;
        
        for (i = 0; i < loop; i++)
        {
            elements = ReadFileIntoArray(argc, argv, &AP);

            #ifdef PRINTARRAY
                PrintArray(AP, elements);
            #endif

            free(AP);

            elements = ReadFileIntoArray(argc, argv, &AP);
            
            start = clock();
            QuickSort(AP, 0, elements-1);
            end = clock();

            printf("Run %d complete : %lu tics\n", i+1, end-start);

            quickSortTime += (end - start);

            #ifdef PRINTARRAY
                PrintArray(AP, elements);
            #endif

            free(AP);
        }

        quickSortTime = quickSortTime / loop;
    }

    printf("The average run time for %d runs is %lu\n\n\n", loop, quickSortTime);
    printf("Processed %d records\n", elements);

    return 0;
}
