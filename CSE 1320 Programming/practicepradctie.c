#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int s, l;
    printf("Enter:");
    scanf("%d", &s);
    int* grades = (int*)malloc(sizeof(int)*s);

    for(l=0;l<s;l+=1)
    {
        printf("Enter: ");
        scanf("%d", &grades[l]);
    }

}