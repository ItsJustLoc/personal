/* 
    Author: Loc Nguyen
    Date: 08/21/2021
    Program: Goto Switch Timmy survival
*/

#include <stdio.h>

int main() {

char Timmy;
printf("Please help me mister, I am starving.\n");
printf(" a. Here have some chicken.\n b. Sorry I don't have anything on me.\n c. Adopt the child.\n");
scanf("%c", &Timmy);

switch(Timmy) 
{
    case 'a': printf("\"Thank You so much mister\"\n"); goto A; break;
    case 'b': printf("\"You later return to see the child has starven to death\"\n"); goto C; break;
    case 'c': printf("\"The child goes on to train and study under your watch.\"\n"); goto B; break;
    default : printf("\"You choose to ignore the child and will never see him again.\"\n"); goto C; break; 
}

A :
    printf("(10 days later)\n");
    printf("You see the child you have fed there in the streets being torn apart by large pack rats.");
    goto END;
B :
    printf("(20 years later)\n");
    printf("The child has grown big and strong and is now taking care of you with his own children and wife.");
    goto END;
C :
    printf("(10 years later)\n");
    printf("Your travels around the contient has amassed to nothing\n");
    printf("(20 years later)\n");
    printf("You are found dead\n");
    goto END;

END :
    return 0;
}
