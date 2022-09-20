#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int index[3]={15,20,0};
    char input[20];

    while(1)
    {
        printf("what perfume\n");
        scanf("%s", input);

        if(!strcmp(input,"exit"))
        {
            printf("exit..\ntotal sprays %d\n", index[2]);
            break;
        }
        else if(!strcmp(input,"Gucci"))
        {
            if(index[0]>10)
            {
                printf("spryaing: starting amount: %d\n", index[0]);
                index[0] = index[0]-5;
                printf("amount left: %d\n", index[0]);
                index[2] = index[2]+1;
            }
            else{
                printf("not enough left\n");
            }
        }
        else if(!strcmp(input,"Chancel"))
        {
                if(index[1]>10)
            {
                printf("spryaing: starting amount: %d\n", index[1]);
                index[1] = index[1]-5;
                printf("amount left: %d\n", index[1]);
                index[2] = index[2]+1;
            }
            else{
                printf("not enough left\n");
            }
        }
        else{
            printf("unkwown perfume\n");
        }
    }
    return 0;
}