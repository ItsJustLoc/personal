// Custom Header File
You can create custom header files in C;
It helps you to manage user-defined methods, global variables, and structures in a separate files, which can be used in different modules.

A process to Create Custom Header File in case

#include<stdio.h>
#include "swap.h"
void main()
{
    int a=20;
    int b=30;
    swap (&a, &b);
    printf("a=%d\n", a);
    printf("b=%d\n", b);
}

Swap method is defined in swap.h file, which is used to swap two numbers by using a temporary variabe.

void swap (int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

header files name must have a .h file extension.
In this example, They have named swap.h header file.
Instead of writing <swap.h> use this terminaology "swap.h" for include custom header file.
Both files swap.h and main.c must be in the same folder.