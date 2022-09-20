#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void enter_prices(float* p, int n);
void print_prices(float* p, int n);

int main(int argc, char** argv)
{
    int n;
    printf("How many items to buy?");
    scanf("%d", &n);

    float* prices = malloc(sizeof(float)*n);

    if(prices==NULL)
    {
        printf("Memory not allocated. Exiting...\n");
    }
    else
    {
        enter_prices(prices, n);
        print_prices(prices, n);

        free(prices);
    }
}

void enter_prices(float* p, int n)
{
    int i;
    for (i=0;i<n;i+=1)
    {
        printf("Enter price of item %d:", (i+1));
        scanf("%f", p);
        p+=1;
    }
}

void print_prices(float* p, int n)
{
    int i;
    float total = 0;
    printf("\n\n***Price list:***\n");
    for (i=0;i<n;i+=1)
    {
        printf("$%.2f\n", p[i]);
        total += p[i];
    }

    printf("\n\n***Total price***\n$%.2f\n", total);
}