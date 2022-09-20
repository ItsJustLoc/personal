// Data Types

Data-type is a set of values and is determined to act on those values. 
Data-types is the collection of data with values having fixed meaning as well as characteristics. 
Some are an integer, floating point, character, etc. 

Data Types are used to:
    Identify the type of a variable when it is declared
    Identify the type of the return value of a function
    Identify the type of a parameter expected by a function

_________________________________________________

ANSI C has 3 types of data types:

Primary Data Types:
    void
    int 
    char 
    double 
    float

Derived Data Types: 
    Array
    References
    Pointers

User Defined Data Types:
    Structure
    Union 
    Enumeration

_________________________________________________

Primary Data Types

void - It holds no value and is used for specifying the type of function or what it returns. If the function has a void type, it means that the function will not return any value.
int - Used to declare an integer type.
char - Used to declare a character type.
float - Used to hold a floating point type.
double - Same as float but more data.
int*, float*, char* - Used to declare a pointer type.

added in C99 
_Bool 
_Complex 
_Imaginary

EX: 
int age;
char letter;
float height, width;



Derived Data Types

Arrays - Arrays are sequences of data items having same values.
References - Functions pointers allow referencing functions with a particular signature.
Pointers - These are used to access the memory and deal with their addresses.



User Defined Data Types

Structure - Package of variables of different types under a single name. struct is the keyword.
Union - Allows storing various data types in the same memory location. Can be defined with different members, but only a single member can contain a value at a given time. 
Enum - Enumeration is a special data type that consists of intergral constants, and ech of them is assigned with a specific name. enum is the keyword.

_________________________________________________

Data Types and Variable Declarations 

#include<stdio.h>
int main()
{
    int a = 4000; // positive integer data type
    float b = 5.2324; // float data type
    char c = 'Z'; // char data type
    long d = 41657; // long positive integer data type
    long e = -21556; // long -ve integer data type
    int f = -185; // -ve integer data type
    short g = 130; // short +ve integer data type
    short h = -130; // short -ve integer data type
    double i = 4.1234567890; // double float data type
    float j = -3.55; // float data type
}