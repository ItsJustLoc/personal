#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4

typedef struct dragon
{
    char name[200];
    char colors[3];
    int head;
    int tail;
}dragon;

void dragon_info(dragon *d);
void color(char* color, dragon *d);


int main(int argc, char** argv)
{
    dragon total[4];
    dragon_info(total);
    char c = 'b';
    color(&c, total);
}

void dragon_info(dragon *d)
{
    int i, len = 300;
    char line[len], *token;

    fgets(line, sizeof(line), stdin);
    token = strtok(line, ",");

    for (i=0;i<SIZE;i+=1)
    {
        token = strtok(NULL, ",");
        strcpy(d[i].name, token);

        token = strtok(NULL, ",");
        d[i].colors[0] = *token;
        token = strtok(NULL, ",");
        d[i].colors[1] = *token;
        token = strtok(NULL, ",");
        d[i].colors[2] = *token;
        
        d[i].head = atoi(strtok(NULL, ","));
        d[i].tail = atoi(strtok(NULL, ","));
    }
}

void color(char* color, dragon *d)
{
    int i, j;
    char color_set[100];

    switch (*color)
    {   
    case 'r':
        strcpy(color_set, "red");
        printf("***All the red dragons:***\n");
        break;        

    case 'b':
        strcpy(color_set, "blue");
        printf("***All the blue dragons:***\n");
        break;

    case 'w':
        strcpy(color_set, "white");
        printf("***All the white dragons:***\n");
        break;

    case 'g':
        strcpy(color_set, "green");
        printf("***All the green dragons:***\n");
        break;
    
    case 'y':
        strcpy(color_set, "yellow");
        printf("***All the yellow dragons:***\n");
        break;

    default:
        break;
    }

    for (i=0;i<SIZE;i+=1)
    {
        for (j=0;j<3;j+=1)
        {
            if (d[i].colors[j]==*color)
            {
                printf("%s is %s.\n", d[i].name, color_set);
            }
        }
    }
}