#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cfilen(char line[], int length);
float bank(char filename[]);

int main(int argc, char** argv)
{
    char line[40];
    int guard = 1;

    while(guard)
    {
        printf("Do you wish to view your current bank statement?\n1. Yes\n2. No\n");
        fgets(line,40,stdin);
        strtok(line,"\n");
        
        if(!strcmp(line, "1") || !strcasecmp(line, "yes"))
        {
            printf("Please input bank name:\n");
            fgets(line,40,stdin);
            strtok(line,"\n");

            cfilen(line, strlen(line));

            float check = bank(line);

            if(check == -1)
            {
                printf("Bank is not in the database..\n");
            }
            else
            {
                printf("Your current bank total is %.2f\n", check);
            }

        }
        else if(!strcmp(line, "2") || !strcasecmp(line, "no"))
        {
            printf("Exiting....\n");
            guard = 0;
        }
    }
}

void cfilen(char line[], int length)
{
    int i;

    for(i=0;i<length;i++)
    {
        if(line[i] == ' ')
        {
            line[i] = '_';
        }
        
        else if(65 <= line[i] && line[i] <=90)
        {
            line[i]+=32;
        }
    }

    strcat(line,".txt");
}

float bank(char filename[])
{
    char line[40];
    float change, total = 1200.00;
    int i = 0;

    FILE* fp = fopen(filename, "r");

    if(!fp)
    {
        return -1;
    }

    else
    {
        while(fgets(line,40,fp))
        {
            change = atoi(line);
            if(0 <= change)
            {
                total += change;
                printf("%d. %.2f\n", i+1, change);
                i++;
            }
            else if(change <= 0)
            {
                total -= change;
                printf("%d. %.2f\n", i+1, change);
                i++;
            }
        }
    }

    fclose(fp);
    return total;
}