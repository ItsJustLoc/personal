/Tokens

Compiler breaks program into smallest units and proceed for various phases of compilation called tokens

Lexical Analysis
Syntax Analysis
Semantic Analysis
Intermediate Code Generation
Machine Independent Code Optimizer
Code Generator
Machine Dependent Code Optimizer

5 Categories of Tokens
//_____________

1. Identifiers
int a=2;
// a is a identifier

2. Literals(constants)
int a=2;
// 2 is constant

3. Keywords
// int, for

4. Operators
// +,-,/,>>

5. SpecialSymbols
// .,#
-------------------
#include<stdio.h>
main()
{
    int a=3;
    printf("hello hai %d",a);


}
//24 tokens
-------------------
1. Identifiers(7)

a 2
main
include
stdio
n
printf

2. Literals(2)

3
hello hai %d

3. Keywords(1)

int

4. Operators(2)

=
,

5. SpecialSymbols(12)
# 1
()x2=4
{}x1=2
;x2=2
<>x1=2
. 1