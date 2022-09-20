// Functions

Functions is a self-contained block of statements that can be executed repetedly whenever we need it.

_________________________________________________________________________________

Benefits of using the functions in C 
    The funtion provides modularity
    The function provides reusable code
    In large programs, debugging and editing tasks is easy with the use of functions
    The program can be modularized into smaller parts
    Separate function independently can be developed according to the needs

There are two types of functions in C 
    Built-in(Library) Functions
        The system provided these functions and store in the library.
        Therefore it is also called Library Functions.
        e.g. scanf(), printf(), strcpy, strlwr, strcmp, strlen, strcat, etc.
        To use these functions, you just need to include the appropriate header files.
    User Defined Functions - are defined by the user at the time of writing the program.

Parts of Function
    1. Function Prototype (function declaration)
    2. Function Definition
    3. Function Call 

1. Function Prototype

dataType functionName (Parameter list)
    int addition();

2. Function Definition

returnType functionName(Funtion arguments){
    //body of the function
}
    int addition(){

    }

3. Calling a function in case

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