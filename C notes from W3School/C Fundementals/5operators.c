// Operators

Operators are symbols that are used to perform mathematical or logical manipulations.
Operators take part in a program for manipulating data and variables and form a part of the mathematical or logical experssions.

There are 8 types of Operators:
    1. Arithmetic Operators
    2. Relational Operators
    3. Logical Operators
    4. Assignment Operators
    5. Increment and Decrement Operators
    6. Conditional Operators
    7. Bitwise Operators
    8. Special Operators
_______________________________

Arithmetic Operators - Used to perform mathematical calculations
    + (Addtion)
    - (Subtraction)
    * (Multiplication)
    / (Division)
    % (Modulus)

EX:
#include<stdio.h>
#include<math.h>
int main()
{
    int i=3,j=7,k; /*Variables Defining and Assign values */
    k=i+j;
    printf("sum of two numbers is %d\n", k);
    return 0;
}

________________________________

Increment and Decrement Operators - Used Generally to minimize the calculation i.e. ++x and x++ means x=x+1 or --x and x-- means x=x-1. 
++ -- written before and after the operand 
Applying the pre-increment first add one to the operand and then the result is assigned to the variable on the left and post-increment first assigns the value to the variable on the left and thenn increment the operand. 

++ Increment x=x+1
-- Decrement x=x-1

EX:
#include<stdio.h>
#include<math.h>
int main()
{
    int a=5, b=5;
    printf("\n%d %d",a--,--b);
    printf("\n%d %d",a--,--b);
    printf("\n%d %d",a--,--b);
    printf("\n%d %d",a--,--b);
    printf("\n%d %d",a--,--b);
    return 0;
}

________________________________

Relational Operators - Used to compare two quantities or values
== Is equal to 
!= Is not equal to 
> Greater than 
< Less than 
>= Greater than or equal to 
<= Less than or equal to 

________________________________

Logical Opertors - Used when testing more than one condition to make decisions.
&& And operator. It performs logical conjunction of two expressions. (if both expressions evaluate to True, result is True. If either expression evaluates to False, the result if False.)
|| Or operator. It performs logical disjunction on two expressions. (if either or both expressions evaaluate to True, the result is True)
! Not operator. It performs logical negation on an expression.

________________________________

Bitwise Operators - Used for bit operation between two variables
<< Binary Left Shift Operator
>> Binary Right Shift Operator
~ Binary Ones Complement Operator 
& Binary AND Operator 
^ Binary XOR Operator 
| Brinary OR Operator 

________________________________

Assignment Operators - Used to assign the result of an expression to a variable.
= Assign
+= Increments then assign 
-= Decrements then assign 
*= Multiples then assign 
/= Divides then assign 
%= Modulus then assign 
<<= Left shift and assign 
>>= Right shift and assign 
&= Bitwise AND assign 
^= Bitwise exclusive OR and assign 
|= Bitwise inclusive OR and assign 

________________________________

Conditional Operator - Used to construct conditional expressions.
?: Conditional Expression

________________________________

Special Operator 
sizeof() Returns the size of a memor location
& Returns the address of a memory location
* Pointer to a variable

EX: 
#include<stdio.h>
#include<math.h>
int main()
{
    int i=10 /* Variables Defining and Assign values */
    printf("integer: %d\n", sizeof(i));
    return 0;
}
