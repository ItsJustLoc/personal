#include<stdio.h>

int addition();

int main()
{
    int answer;
    answer = addition();

    printf("The addition of the two numbers is: %d\n", answer);
    return 0;
}

int addition()
{
    int num1 = 10, num2 = 5;
    return num1+num2;
}