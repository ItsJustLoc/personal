#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ORDER{
    char* f_name;
    char* l_name;
    char* method;
    int* items;
    float* payment;
    int* full;
}order;

void input_orders(order *o, int size, char*filename);
void print_out(int status, order*o, int size);
int pick_next(order *o, int size_order);
void output_file(char*filename, order *o, int size_order);

int main(int argc, char** argv)
{
    int num = atoi(argv[1]), quit = 1, stat, i;
    char input[20];

    order* orders = malloc(sizeof(order)*num);

    printf("\n***Buongiorno Chef Bartolomeo!***.\n");

    input_orders(orders, num, argv[2]);

    while (quit)
    {
        printf("\nWhat to do?\n");
        printf("1. print out orders\n");
        printf("2. pick next order to fulfill\n");
        printf("3. exit\n");
        scanf("%s", input);
        if (!strcmp(input, "1"))
        {
            printf("\nDo you want to see all orders to fill or orders already completed? Type fill or completed\n");
            scanf("%s", input);

            if (!strcmp(input, "fill"))
            {
                stat = 2;
                print_out(stat, orders, num);
            }
            else if (!strcmp(input, "completed"))
            {
                stat = 1;
                print_out(stat, orders, num);
            }
        }
        else if (!strcmp(input, "2"))
        {
            i = pick_next(orders, num);

            if (i == -1)
            {
                printf("No more orders to fulfill.\n");
            }
            else if (i || i == 0)
            {
                printf("\nNext order to fill: %s %s\n", orders[i].f_name, orders[i].l_name);
                printf("Go ahead and fulfill this order? y or n\n");
                scanf("%s", input);
            
                if (!strcmp(input, "y"))
                {
                    *orders[i].full = 1;
                    printf("Fulfilled!\n");
                }
                else if (!strcmp(input, "n"))
                {
                    printf("Not fullfilled.\n");
                }
            }
        }
        else if (!strcmp(input, "3"))
        {
            printf("Saving information...Ciao!\n");
            output_file(argv[2], orders, num);
            quit = 0;
        }
        else
        {
            printf("Not a valid menu choice.\n");
        }
    }

    free(orders);
}

void input_orders(order *o, int size, char*filename)
{
    int i = 0, len = 200;
    char line[len], * token;

    FILE* fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Error opening file.\n");
    }
    else
    {
        while (fgets(line, sizeof(line), fp) && i < size)
        {
            token = strtok(line, " ");
            o[i].f_name = malloc(sizeof(token)+1);
            strcpy(o[i].f_name, token);

            token = strtok(NULL, ",");
            o[i].l_name = malloc(sizeof(token)+1);
            strcpy(o[i].l_name, token);

            token = strtok(NULL, ",");
            o[i].method = malloc(sizeof(token)+1);
            strcpy(o[i].method, token);

            token = strtok(NULL, ",");
            o[i].items = malloc(sizeof(int));
            *o[i].items = atoi(token);

            token = strtok(NULL, ",");
            o[i].payment = malloc(sizeof(float));
            *o[i].payment = atof(token);

            token = strtok(NULL, "\n");
            o[i].full = malloc(sizeof(int));
            *o[i].full = atoi(token);

            i+=1;
        }
    }
    fclose(fp);
}

void print_out(int status, order*o, int size)
{
    int i;
    char input[10];

    if (status == 2)
    {
        printf("Need to fill:\n");

        for (i=0;i<size;i+=1)
        {
            if (*o[i].full == status)
            {
                printf("%s %s\n", o[i].f_name, o[i].l_name);
            }
        }
    }
    else if (status == 1)
    {
        printf("Already filled:\n");

        for (i=0;i<size;i+=1)
        {
            if (*o[i].full == status)
            {
                printf("%s %s\n", o[i].f_name, o[i].l_name);
            }
        }
    }
}

int pick_next(order *o, int size_order)
{
    int i, counter = 0, track = 0;
    char input[10];
    float best = 0;

    for (i=0;i<size_order;i+=1)
    {
        if ((*o[i].payment) > best && *o[i].full == 2)
        {
            best = *o[i].payment;
            counter = i;
            track+=1;
        }
    }
    if (track == 0)
    {
        return -1;
    }
    else
    {
        return counter;
    }
}

void output_file(char*filename, order *o, int size_order)
{
    int i;
    FILE* fp = fopen(filename, "w");

    for (i=0;i<size_order;i+=1)
    {
        fprintf(fp, "%s %s,%s,%d,%.2f,%d\n", o[i].f_name, o[i].l_name, o[i].method, *o[i].items, *o[i].payment, *o[i].full);
    }

    fclose(fp);
}