// Recursion

C is a programming language having capabilities like an iteration of a set of statements 'n' number of times.
The same concepts can be done using functions also.
In this chapter, you will be learning about recursion concept and how it can be used in the C program.

Recursion - can be defined as the technique of replicating or doing again an activity in a self-similar way calling itself again and again, and the process continues till specific condition reaches.

void rec_prog(void) {
    rec_prog(); /* function calls itself */
}

int main(void) {
    rec_prog();
    return 0;
}

C program allows you to do such calling of function within another function, i.e., recursion.
But when you implement this recursion concept, you have to be catious in defining an exit or terminating condition from this recursive function, or else it will continue to an infinite loop, so make sure that the condition is set within your program.