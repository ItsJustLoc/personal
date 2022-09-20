// If Statements

If statement in C is used to control the program flow based on some condition, its used to execute some statement code block if the expression is true. Otherwise, it will get skipped.

There are four types of if statements:
    if statement
    if-else statement
    Nested if-else statement
    else-if Ladder
______________________________________________________

If Statement

if(test_expression) 
{
    statement 1;
    statement 2;
    ...
}

'Statement n' can be a statement or a set of statements, and if the test expression is evaluated to true, the statement block will get executed, or it will get skipped.
  Start
    |
    |
Expression ---
    |         |
  True        |
    |         |
Statement   False
    |         |
    |         |
    |         |
   Stop ------

______________________________________________________

If-Else Statement - used to control the program flow based on some condition, only the difference is: its used to execute some statement code block if the expression is evaluated to true, otherwise executes else statement code block.

if(test_expression)
{
    //execute your code
} else {
    //execute your code
}
  Start
    |
    |
Expression ---
    |         |
  True        |
    |         |
Statement   False
    |         |
    |         |
    |         |
   Stop ------

______________________________________________________

Nested If-Else Statement - plays an important role in C programming, it means you can use conditional statements inside another conditional statement.

if(test_expression one)
{
    if(test_expression two) {
        //Statement block Executes when the boolean test expression two is true.
    }
} else {
    // else statement block
}

______________________________________________________

Else-If Statements - is another if condition, its used in a program when if statement having multipple decisions.
if(test_expression)
{
    //excute your code
} else if(test_expression n) {
    //execute your code
} else {
    //execute your code
}