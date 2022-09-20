#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int registered(FILE *fp);
void new_register(FILE *fp);

int main(int argc, char** argv)
{
    int i, result, num, num_res;
    char answer[100];
    FILE* fp = fopen(argv[1], "r");

    result = registered(fp);

    fclose(fp);

    do
    {
        printf("\nHow many people to ask right now?\n");
        fgets(answer, 100, stdin);
        num = atoi(answer);

        for(i=0;i<num;i+=1)
        {
            printf("\n-Person %d: Would you like to register to vote?", (i+1));
            fgets(answer, 100, stdin);
            strtok(answer, "\n");

            if(!strcmp(answer, "n"))
            {
                printf("Ok\n");
            }
            else if(!strcmp(answer, "y"))
            {
                fp = fopen(argv[1], "a+");
                new_register(fp);
                fclose(fp);
                
                fp = fopen(argv[1], "r");
                result = registered(fp);
                fclose(fp);
            }
        }

        if(result >= 10)
        {
            printf("\nTarget reached! Exiting...\n");
        }
        else
        {
            printf("\n%d people asked! Taking a break.\n", num);
        }
    }while(result < 10);
}

int registered(FILE *fp)
{
    int i = 0, count = 0, line_len = 100;
    char line[line_len];

    printf("\n***Registered so far***\n");

    while(fgets(line, line_len, fp))
    {
        printf("%d. %s", (count+1), line);
        count+=1;
    }
    rewind(fp);

    return count;
}

void new_register(FILE *fp)
{
    char answer[200];

    printf("Enter name: ");
    fgets(answer, 200, stdin);
    printf("Adding: %s", answer);
    fprintf(fp, "%s", answer);
}