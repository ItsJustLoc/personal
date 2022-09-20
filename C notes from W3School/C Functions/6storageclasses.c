// Storage Classes

Storage Classes are associated with variables for describing he features of any variable or function in the C program.
These storage classes deal with features such as scope, lifetime and visibility which helps programmers to define a particular variable during the programs runtime.
These storage classes are preceded by the data type which they had to modify.

There are four storage classes types in C:
    auto
    register
    static
    extern 

______________________________________________________________________

auto Storage Classes
auto comes by default with all local variables as its storage class. The keyword auto is used to define this storage class explicity

int roll; // contains auto by default

is the same as: 

auto int roll; /// in addition, we can use auto keyword.

______________________________________________________________________

register Storage Class
storage class is implemented for classifying local variables whose value needs to be saved in a register in place of RAM (Random Access Memory). 
This is implemented when you want your variable the maximum size equiveent to the size of the register.
It uses the keyword register

register int counter;

Register variables are used when implementing looping in counter variables to make program execution fast.
Register variables work faster than variables stored in RAM (primary memory)

______________________________________________________________________

static storage class
This storage class uses static variables that are used popularly for writing programs in C language.
Static vairables preserve the value of a variables even when the scope limt exceeds
Static storage class has its scope local to the function in which it is defined.

Global static variables can be accessed in any part of your program.
The default value assigned is '0' by the C compiler.
The keyword used to define this storage class is static.

static int var = 6;

______________________________________________________________________

extern Storage class
This extern storage class is used to feature a variable to be used from within different blocks of the same program.
A value is set to that variable which is in a different block or function and can be overwritten or altered from within another block as well.
Therefore it can be said that an extern variable is a global variable which is assigned with a value that can be accessed and used within the entire program.
A global variable can be explicity made an extern variable by implementing the keyword 'extern' preceded the variable name.

#include<stdio.h>

int val;
extern void funcExtern();

main()
{
    val = 10;
    funExtern();
}

______________________________________________________________________

#include<stdio.h>

extern int val; // now the variable val can be accessed and used from anywhere

// within the program
void funcExtern()
{
    printf("Value is: %d\n", val);
}