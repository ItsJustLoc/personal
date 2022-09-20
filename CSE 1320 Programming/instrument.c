#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct instr{
    char name[25];
    float price;
    char family;
};

typedef struct instr instrument;

int read_file(int nums, instrument* n, char* c);
int least_expensive(instrument* n, int nums);
void print_info(instrument n);

int main(int argc, char** argv)
{
    instrument symphony[18];
    instrument* ptr=symphony;

    int l = read_file(18, ptr, argv[1]);

    if (l)
    {
        int n=least_expensive(ptr, 18);
        print_info(symphony[n]);
    }

    return 0;
}

int read_file(int nums, instrument* n, char* c)
{
    FILE* fp = fopen(c, "r+");

    int i = 0;
    char line[100];
    char* token;

    if (!fp)
    {
        printf("Error opeening file\n");
        return 0;
    }
    else
    {
        while (i < nums)
        {
            fgets(line, 100, fp);

            token=strtok(line, ",");
            strcpy(n[i].name, token);

            token=strtok(NULL, ",");
            n[i].price=atof(token);

            token=strtok(NULL, ",\n");
            n[i].family=token[0];

            i++;
        }

        fclose(fp);
        return 1;
    }
}

int least_expensive(instrument* n, int nums)
{
    float hold = n[0].price, current = 0;
    int i;
    int index = 0;

    for (i=0;i<nums;i+=1)
    {
        current = n[i].price;
        if(current<hold)
        {
            hold = n[i].price;
            index = i;
        }
    }

    return index;
}

void print_info(instrument n)
{
    char family[15];

    switch(n.family)
    {
    case'k': 
      strcpy(family, "keyboards"); 
      break; 
    case's': 
      strcpy(family, "strings"); 
      break; 
    case'b': 
      strcpy(family, "brass"); 
      break; 
    case'p': 
      strcpy(family, "percussion"); 
      break; 
    case'w': 
      strcpy(family, "woodwind"); 
      break; 
    default: 
      strcpy(family,"unknown"); 
    }

    printf("\n**Least expensive: %s at $%.2f. It is from the %s, family\n\n", n.name, n.price, family);
}