// Variable Scope

A scope is a region of the program, and the scope of variables refers to the area of the program where the variables can be accessed after its declaration.

In C every variable defied in scope.
You can define scope as the section or region of a pprogram where a variable has its existence; moreover, that variable cannot be used or accessed beyond that region.

In C programing, variable declared within a function is different from a variable declared outside of a function. 
The variable can be declared in three places.
These are:
    Inside a function or a block - Local variables
    Out of all functions - Global variables
    In the function parameters - Formal parameters

____________________________________________________________________

Local Variables - Variables that are declared within the function block and can be used only within the function is called local variables.

Local Scope or Block Scope - is collective program statements put in and declared within a function or block (a specific region enclosed with curly braces) and variables lying inside such blocks are termed as local variables.
All these locally scoped statements are written and enclosed within left '{' and right braces '}' curly braces.
Theres a provision for nested blocks also in C which means there can be a block or a function within another block or function. 
So it can be said that variable(s) that are declared within a block can be accessed within that specific block and all other inner blocks of that block, but those variables cannot be accessed outside the block.

#include<stdio.h>

int main()
{
    /* local variable definition and initialization */ int x, y ,z;
    /* actual initialization */ x = 20;
    y = 30;
    z = x + y;

    printf("Value of x = %d, y = %d and z = %d\n", x, y, z);

    return 0;
}

Global Variable - Variables that are declared outside of a function block and can be accessed inside the function is called global variables.

Global Scope - are defined outside a function or any specific block, in most of the case, on the top of the C program.
These variables hold their values all through the end of the program and are accessible within any of the functions defined in your program.

Any function can access variables defined within the global scope, i.e., its availablility stays for the entire program after being declared.

#include<stdio.h>

/* global variable definition */ int z;

int main()
{
    /* local variable definition and initialization */ int x, y;

    /* actual initialization */ x = 20;
    y = 30;
    z = x + y;

    printf("value of x = %d, y + %d and z = %d\n", x, y ,z);

    return 0;
}

Global Variable Initialization - After defining a local variable, the system or the compiler wont be initializing any value to it.
You have to initialize it by yourself.
It is considered good programming practice to initialize variables before using.
Whereas in contrast, global variables get initialized automatically by the compiler as and when defined.
Heres how based on datatype; global variables are defined.

int - 0
char - '\0'
float - 0
double - 0
pointer - NULL