/*  Author: Loc Nguyen
    Date: 8/17/2021
    Program: If Else statments
*/

#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    printf("Put two number to see which is greater: ");
    scanf("%d %d", &a, &b);
    if (a > b) printf("A is Greater");
    if (b > a) printf("B is Greater");
    if (a == b) printf("They are Equal");
    else printf("Please input two valid numbers");
    return 0;
}