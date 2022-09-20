#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person{
    char* first_name;
    char* last_name;
    int* number_order_registered;
};

typedef struct person PERSON;

int numf(char* arg);
void savef(char* arg, PERSON* pers, int num, int* vote);
void freef (PERSON* pers, int num, int* vote);

int main(int argc, char** argv)
{
    int i, len = 200;
    char line[len];
    int num = numf(argv[1]);

    PERSON* info = malloc(sizeof(PERSON)*num);
    int* vote = malloc(sizeof(int)*num);

    savef(argv[1], info, num, vote);

    FILE* fp = fopen(argv[2], "w+");

    for (i=0;i<num;i+=1)
    {
        printf("-%s, %s...%d!\n", info[i].last_name, info[i].first_name, *(info[i].number_order_registered));
        fprintf(fp, "-%s, %s...%d!\n", info[i].last_name, info[i].first_name, *(info[i].number_order_registered));
    }

    fclose(fp);
    
    freef(info, num, vote);
    return 0;
}

int numf(char* arg)
{
    int i, len = 200;
    char line[len];
    FILE* fp = fopen(arg, "r+");
    
    while (fgets(line, sizeof(line), fp))
    {
        i+=1;
    }
    rewind(fp);

    fclose(fp);
    return i;
}

void savef(char* arg, PERSON* pers, int num, int* vote)
{
    int i = 0, len = 200;
    char line[len], *token;
    FILE* fp = fopen(arg, "r+");

    if (!fp)
    {
        printf("Error opening file.\n");
    }
    else
    {
        int* lol = malloc(sizeof(int)*num);
        while (fgets(line, sizeof(line), fp) && i < num)
        {
            token = strtok(line, " ");
            pers[i].first_name = malloc(sizeof(token)+1);
            strcpy(pers[i].first_name, token);
            //printf("%s\n", pers[i].first_name);

            token = strtok(NULL, "\n");
            pers[i].last_name = malloc(sizeof(token)+1);
            //pers[i].last_name = strtok(NULL, "\n");
            strcpy(pers[i].last_name, token);
            //printf("%s\n", pers[i].last_name);

            pers[i].number_order_registered = malloc(sizeof(int));
            vote[i] = (i+1);
            pers[i].number_order_registered = &vote[i];

            //printf("%d\n", *(pers[i].number_order_registered));

            i+=1;
        }
    }
    
    fclose(fp);
}

void freef (PERSON* pers, int num, int* vote)
{
    free(vote);
    free(pers);
}