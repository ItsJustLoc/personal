#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float print_out(float* salary, int* num_of_emps);
int rebudget(float* d, float *budget);

int main(int argc, char** argv)
{
   int i=1;
   float budget, total, salary;
   float* money_ptr=&salary;
   float* total_ptr=&total;
   int employees;

   printf("Enter monthly budgets: $");
   scanf("%f", &budget);

   while(i)
   {
       printf("Enter monthly worker salary: $");
       scanf("%f", &salary);

       printf("Enter total workers:");
       scanf("%d", &employees);

       total=print_out(money_ptr, &employees);
       i=rebudget(total_ptr, &budget);
   } 
}

float print_out(float* salary, int* num_of_emps)
{
    char type[3][20] = {"Worker", "Manager", "Director"};
    float dirs = *salary*5;
    float mans = dirs/2;
    int manas;
    int dires;
    int clone;
    
    if(*num_of_emps%2 == 0)
    {
        manas = *num_of_emps/2;
    }
    else if(*num_of_emps%2 == 1)
    {
        manas = *num_of_emps/3 + *num_of_emps%3;
    }

    if(manas%3 == 0 || manas%3 <= 3)
    {
        dires = manas/3;

        if(manas%3 >= 3)
        {
            dires++;
        }
    }

    printf("\n\n**Employee info:**\n");
    printf("Total %ss: %d\tMonthly salary: $%.2f\n", type[0], *num_of_emps, *salary);
    printf("Total %ss: %d\tMonthly salary: $%.2f\n", type[1], manas, mans);
    printf("Total %ss: %d\tMonthly salary: $%.2f\n", type[2], dires, dirs);
    float totalemp = ((*salary * *num_of_emps) + (mans * manas)+ (dirs * dires));
    printf("Total spent: %.2f", totalemp);
    return totalemp;



}

int rebudget(float* d, float *budget)
{
    if(*budget - *d <= *budget)
    {
        printf("\n-This goes UNDER your budget by $%.2f.\n", *budget - *d);
    }
    if(*budget - *d >= *budget)
    {
        printf("\n-This goes OVER your budget by $%.2f.\n", *d - *budget);
    }
    int would;
    printf("\n\n--------\nWould you like to rebudget? 1 for yes 2 for no.\n");
    scanf("%d", &would);

    if(would == 1)
    {
        return 1;
    }
    else if(would == 2)
    {
        return 0;
    }
}