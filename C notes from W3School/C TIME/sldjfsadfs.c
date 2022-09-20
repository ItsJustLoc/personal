#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int donation, total = 0, target = 100;
    char charity[20];

    while(1)
    {
        printf("***Welcome! Are you looking to donate or do you work here?\n");
        scanf("%s", charity);

        if(!strcmp(charity,"exit"))
        {
            break;
        }
        
        else if(!strcmp(charity,"donate") && total < target)
        {
            printf("Great! How much? $");
            scanf("%d", &donation);
            total = total + donation;
        }
        
        else if(!strcmp(charity,"work"))
        {
            printf("Total donated so far: $%d\n", total);
        }

        if(total > target && !strcmp(charity,"donate"))
        {
            printf("We already met our target but thanks!\n");
        }
    }

}