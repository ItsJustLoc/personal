// Preprocessors

The preprocessor is a program invoked by the compiler that modifies the source code before the actual composition takes place.

__________________________________________________________________________________________________________________________________________________

Macro substitution division

#include - File include

#define
        - Macro define, Macro undefine
#undif

#ifdef
        - If macro defined, if macro not defined
#ifndef
 
__________________________________________________________________________________________________________________________________________________

File inclusion division

#if
#elif
        -If, Else, ifElse, End if
#else
#endif

__________________________________________________________________________________________________________________________________________________

Compiler control division

#line
#error - Set line number, Abort compilation, Set compiler option
#pragma

__________________________________________________________________________________________________________________________________________________

#include<stdio.h>

/* #define macro_name character_sequence */
#define LIMIT 10

int main()
{
    int counter;
    for(counter = 1; counter <= LIMIT; counter++)
    {
        printf("%d\n", counter);
    }
    return 0;
}

// The code above the loop will run ten times

#include<stdio.h> - tells the compiler to add stdio.h file from system libraries to the current source file
#include "header.h" - tells the compiler to get header.h from the local directory

#undef LIMIT
#define LIMIT

// Tells the compiler to undefine existing LIMIT and set it as 20

#ifndef LIMIT
    #define LIMIT 50
#endif

// Tells the compiler to define LIMIT, only if LIMIT isn't already defined.

#ifdef LIMIT
    /* Your statements here */#endif

//Tells the compiler to do the process the statements enclosed if LIMIT is defined

