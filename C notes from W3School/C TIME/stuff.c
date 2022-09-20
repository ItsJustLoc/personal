#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int length, width;

    printf("Enter a length: \n");
    scanf("%d", &length);
    printf("Enter a width: \n");
    scanf("%d", &width);

    for(int b = 0; b < length/2+2; b++)
    {
        for(int c = 0; c < width; c++)
        {
            if(c == 0 || b==0 || c==width-1 || b==length/2+2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}