// GoTo Statement

goto statement is used to branch unconditionally within a program from one point to another.
Although it is not a good habit to use the goto statement in C, there may be some situations where the use of the goto statement might be desirable.

The goto statement is ued by programmers to change the sequence of execution of a C program by shifting the control to a different part of the same program.

goto label;

A label is an identifier required for goto statement to a place where the branch is to be made. 
A label is a valid variable name which is followed by a colon and is put immediately before the statement where the control needs to be jumped/transferred unconditionally.

goto label; 

- - -- -   -
- - - - - - - - 

label:

statement - X;
/* This the foward jump of goto statement */

or 

label:

- - -- -   -
- - - - - - - - 

goto label;
/* This is the backward jump of goto statement */