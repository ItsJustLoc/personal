// Array
The array is a data structure in C programming, which can store a fixed-size sequential collection of elements of the same data type.

For example, if you want to store ten numbers, it is easier to define an array of 10 lengths, inst4ead of defining ten variables.

In the C programming language, an array can be One-Dimensional, Two-Dimensional, and Multidimensional

__________________________________________________________________________________________________________________________________________________

Define an Array in C 

SYNTAX
type arrayName [ size ];

This is a one-dimensional array. An array type can be any valid C data types, and array size mnust be an integer constant greater than zero.

double amount[5];

__________________________________________________________________________________________________________________________________________________

Initialize an Array in C 
Arrays can be initialized at declarationn time:
int age[5]={22,25,30,32,35};

Initializing each element separately in a loop:
int myArray[5];
int n = 0;

// INitializing elements of array seperately
for(n=0;n<sizeof(myArray)/sizeof(myArray[0]);n++)
{
    myArray[n] = n;
}

age[0] = 22
age[1] = 25
age[2] = 30
age[3] = 32
age[4] = 35

__________________________________________________________________________________________________________________________________________________

Accessing Array Elements in C 

int myArray[5];
int n = 0;

// Initializing elements of array seperately
for(n=0;n<sizeof(myArray)/sizeof(myArray[0]);n++)
{
    myArray[n] = n;
}

int a = myArray[3]; // Assigning 3rd element of array value to integer 'a'.