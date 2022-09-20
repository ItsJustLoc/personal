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

void insertionSort(int v[], int s) 
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

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for  (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int L, int R)
{
    if (L < R)
    {
        int M = (L+R) / 2;

        mergeSort(arr, L, M);
        mergeSort(arr, M+1, R);

        merge(arr, L, M, R);
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
    int elements;
    unsigned long mergeSortTime;
    clock_t start, end;

    elements = ReadFileIntoArray(argc, argv, &AP);

    #ifdef PRINTARRAY
        PrintArray(AP, elements);
    #endif

    start = clock();
    mergeSort(AP, 0, elements-1);
    end = clock();

    mergeSortTime = end - start;

    #ifdef PRINTARRAY
        PrintArray(AP, elements);
    #endif

    free(AP);

    elements = ReadFileIntoArray(argc, argv, &AP);

    #ifdef PRINTARRAY
        PrintArray(AP, elements);
    #endif

    start = clock();
    insertionSort(AP, elements);
    end = clock();

    #ifdef PRINTARRAY
        PrintArray(AP, elements);
    #endif

    printf("Processed %d records\n", elements);
    printf("Merge Sort     = %lu\n", mergeSortTime);
    printf("Insertion Sort = %lu\n", end-start);

    free(AP);
    return 0;
}
