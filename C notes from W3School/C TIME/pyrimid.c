#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



int main()
{
    int number, l, counter = 1;
    
    printf("Enter a how tall you want your pyrimid to be: \n");
    scanf("%d", &number);
    for(int i = 0; i < number; i++)
    {
        for(int k = i; k < number; k++)
        {
            printf(" ");
        }
        for(int j = 0; j < counter; j++)
        {
            printf(" * ");
        }
        counter += 2;
        printf("\n");
    }
}