#include<stdio.h>

//call by reference

int addition(int *num1, int *num2);

int main()
{
    int answer;
    int num1 = 10;
    int num2 = 5;
    answer = addition(&num1, &num2);

    printf("The addition of two numbers is: %d\n", answer);

    return 0;
}
int addition(int *a, int *b)
{
    return *a + *b;
}