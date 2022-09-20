// Variables

The primary use of variables is to store data in memory for later use. Unlike constants which do not change during the program execution, variables value may change during execution. 
If you declare a variable in C, that means you are asking the operating system to reserve a piece of memory with that variable name.

______________________________________________________

SYNTAX of variable

type variable_name;
type variable_name, variable_name, variable_name;



Variable Declaration and Initialization

int width, height=5;
char letter='A';
float age, area;
double d;

/* actual initialization */width = 10;
age = 26.5;
area = width * height;



Variable Assignment 

int width = 60;
int age = 31;

______________________________________________________

Rules for choosing variable names
    A-Z,a-z,0-9,__
    First character MUST be a letter or _
    Blank spaces are not allowed in variable names.
    special characters like #,$ are not allowed.
    Keywords cannot be used in variable names.
    Variable names are case sensitive.
    Variable type can be char, int, float, double, or void
 