// Switch Statement

Switch Statement is usde when you have multiple possibilities for the if statement.
Switch case will allow you to choose from multiple options. 
When we compare it to a general electric switchboard, you will have many switches in the switchboard but you will only select the required switch.
The switch case allows you to set the necessary statements for the user.

switch(var)
{
    case 1:
    //execute your code
    break;
    
    case n:
    //execute your code
    break;

    default:
    //execute your code
    break;
}

After the end of each block it is necessary to insert a break statemtn because if the programmer does not use the break statement, all consecutive blocks of codes will get executed from every case onwards after matching the case block.

When none of the csae is evaluated to true, the default case will be executed, and break statement is not required for default statement.

* refer to "Nested Switch Statements"