// Strings

Int C programming, the one-dimensional array of characters are called strings, which is terminated by a null character '\0'.

Strings Declaration in case

Through an array of charaters
char name[6];

Through pointers.
char *name;

__________________________________________________________________________________________________________________________________________________

Strings Initialization in C 

char name[6] = {'C', 'l', 'o', 'u', 'd', '\0'};

char name[] = "Cloud";

char name[0] = C 
char name[1] = l 
char name[2] = o 
char name[3] = u 
char name[4] = d 
char name[5] = \0

#include<stdio.h>

int main()
{
    char name[6] = {'C', 'l', 'o', 'u', 'd', '\0'};

    printf("Tutorials%s\n", name);

    return 0;
}

Output : TutorialsCloud