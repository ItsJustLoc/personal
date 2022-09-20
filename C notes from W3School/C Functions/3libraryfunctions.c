// Library Functions

//The C library functions are provided by the system and stored in the library. The C library function is also called an inbuild function in C programming.

//To use Inbuilt Function in C, you must include their respective header files, which contain prototypes and data definitions of the function.

//____________________________________________________________

//C Program to Demonstrate the Use of Library Functions

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void main()
{
    int i = -10, e = 2, d = 10;
    float rad = 1.43;
    double d1 = 3.0, d2 = 4.0;

    printf("%d\n", abs(i));
    printf("%f\n", sin(rad));
    printf("%f\n", cos(rad));
    printf("%f\n", exp(e));
    printf("%f\n", log(d));
    printf("%f\n", pow(d1, d2));
}