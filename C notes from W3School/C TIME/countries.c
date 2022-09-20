#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char**argv)
{
    char countries[4][20];
    char capitals[4][20];
    char answer[20];

    int value = 1;
    int i, j, k;
    
    for(i=0; i<4; i++)
    {
        printf("\n--Enter a country: ");
        fgets(countries[i],20,stdin);
        strtok(countries[i],"\n");

        for(j=0; j<strlen(countries[i]); j++)
        {
            countries[i][j]=tolower(countries[i][j]);
        }

        printf("Saved: %s\n", countries[i]);

        printf("Enter capital of %s: ", countries[i]);
         fgets(capitals[i],20,stdin);
        strtok(capitals[i],"\n");

        for(j=0; j<strlen(capitals[i]); j++)
        {
            capitals[i][j]=tolower(capitals[i][j]);
        }

        printf("Saved: %s\n", capitals[i]);
    }

    printf("\n~~~~~~\n");

    while(value)
    {
        printf("\nEnter a capital or country: ");
        fgets(answer,20,stdin);
        strtok(answer, "\n");

        if(!strcasecmp(answer, "exit"))
        {
            value=0;
        }
        
        for(i=0; i<4; i++)
        {
            if(!strcasecmp(answer,countries[i]))
            {
                printf("The capital of that country is: %s\n", capitals[i]);
            }

            else if(!strcasecmp(answer,capitals[i]))
            {
                printf("That is the capital of: %s\n", countries[i]);
            }
        }
    }

}