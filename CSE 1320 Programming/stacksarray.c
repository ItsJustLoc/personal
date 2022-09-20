#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 6
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct stack {  
    int values[STACK_LENGTH];
    int top;
} stack;

bool push(stack* mystack, int value) {
    if (mystack->top >= STACK_EMPTY-1) return false;

    mystack->top+=1;
    mystack->values[mystack->top] = value;
    return true;
}

int pop(stack* mystack) {
    if (mystack->top == EMPTY) return STACK_EMPTY;

    int result = mystack->values[mystack->top];
    mystack->top-=1;
    return result;
}

int main(void)
{
    stack s1;
    s1.top = EMPTY;
    stack s2;
    s2.top = EMPTY;
    stack s3;
    s3.top = EMPTY;


    push(&s1, 56);
    push(&s2, 78);
    push(&s2, 13);
    push(&s2, 50);
    push(&s3, 72);
    push(&s1, 99);

    int t;
    while ((t = pop(&s2)) != STACK_EMPTY) {

        printf("t = %d\n", t);
    }
}