// Header Files

C is famous for its different libraries and the predefined functions pre-written within it. These libraries make programming easier. 

What are the Header Files
Header Files - helping files of your C program which holds the definitions of various functions and their associated variables that needs to be imported into your C program with the help of pre-processor #include statement.
Alle the header file have a '.h' an extension that contains C function declaration and macro definitions.
The header files can be requested using the preprocessor dirctive #include.
The default header file that comes with the C compiler is the stdio.h

Including a header file means that using the content of header file in your source program.
A practice while programming in C or C++ programs is that you can keep every macro, global variables, constants, and other function prototypes in the header files. 

SYNTAX
#include<file>
or
#include"file"

This file inclusion is implemented for including system oriented header files.
This technique (with angular braces) searches for file-name in the standard list of system directories or within the compilers directory of header files.
The second kind of header file is used for user-defined header files or other external files for your program.
This technique is used to search for the file(s) within the directory that contains the current file.

__________________________________________________________________________________________________________________________________________________

How include works

#include preprocessor directive statement tries to go through the C preprocessors to scan for a specific file, such as input, before follwing the rest of the existing source file.

char *example (void);

#include<stdio.h>

int x;
#include "karl.h"
int main ()
{
    printf("Program done");
    return 0;
}

Compiler will see the entire C program and token stream as:

#include<stdio.h>

int x;
char * example (void);
int main()
{
    printf("Program done");
    return 0;
}

__________________________________________________________________________________________________________________________________________________

Writing of Single and Multiple uses of Header files
You can use various header files based on some conditions. In case, when a header file needs to be included twice within your program, your compiler will be going to process the contents inside it - twice which will eventually lead to an error in your program.
So to eliminate this, you have to use conditional preprocessor directices.

SYNTAX
#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME
    the enter header file
#endif 

Sometimes its essential for selecting several diverse header files based on some requirement to be incorporated into your program.
For this multiple conditional preprocessors can be used like this:

SYNTAX
#if FIRST_SYSTEM
    #include "sys.h"
#elif SEC_SYSTEM
    #include "sys2.h"
#elif THIRD_SYSTEM
    ....
#endif 