/* 
    Author: Loc Nguyen
    Date: 08/17/2021
    Program: Input/Output
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    char n[100], p[100];
    printf("What is your name: \n");
    scanf("%s %s", n, p);
    printf("How old are you: \n");
    scanf("%d", &a);
    printf("What year were you born in: \n");
    scanf("%d", &b);
    printf(" Your name is %s %s \n You are %d \n You were born in %d \n", n, p, a, b);
    return 0;
}