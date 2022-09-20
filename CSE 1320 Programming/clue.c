#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

int meet_with_suspect(char *suspect[], int meat[3], char nmae[]);

int main(int agrc, char **argv)
{
    char *all_suspects[]={"Mustard", "Scarlet", "Plum"};
    int meet[3]={0};
    char name[100];
    int check=1;

    while(check)
    {
        printf("\n***Enter a suspect's name: ");
        fgets(name,100,stdin);
        strtok(name,"\n");

        if(!strcmp(name, "exit"))
        {
            check=0;
        }

        else
        {
            check=meet_with_suspect(all_suspects,meet,name);
        }
    }

    printf("Total meets for Mustard: %d\n", meet[0]);
    printf("Total meets for Scarlet: %d\n", meet[1]);
    printf("Total meets for Plum: %d\n", meet[2]);
}

int meet_with_suspect(char *suspect[], int meat[3], char nmae[])
{
    int i, count=0;
    char input[10];

    for(i=0;i<SIZE;i++)
    {
        if(!strcmp(nmae, suspect[i]))
        {
            printf("Suspect found. Adding meeting.\n");
            meat[i]++;
            count++;
        }
    }

    if(count==0)
    {
        printf("Suspect not found.\n");
    }

    printf("--Would you like to continue meeting?\n");
    fgets(input,100,stdin);
    strtok(input,"\n");
    
    if(!strcmp(input, "yes"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}