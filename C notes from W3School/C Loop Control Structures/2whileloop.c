// WHile Loops

C while loops statement allows to epeatedly run the same block of code until a condition is met.
while loop is a most basic loop in C programming.
while loop has one control condition, and executes as long as the condition is true.
The condition of the loop is tested before the body of the loop is executed, hence it is called an entry-controlled loop.

while (condition)
{
    statement(s);
    Incrementation;
}

            Start
             |
             |
    --->Evaluate Condition ----------
    |        |                       |
    |        |                       |
    |      True                      |
    |        |                       |
    |        |                       |
    ----Execute Statments          False
                                     |                       
                                     |                       
                           Stop<-----