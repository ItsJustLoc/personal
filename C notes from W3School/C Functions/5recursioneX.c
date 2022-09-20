#include<stdio.h>
#include<stdlib.h>

int fact(int f) {
    if (f <= 1) {
        printf("Calculated Factorial\n");
        return 1;
    }
    return f * fact(f -1);
}

int main(void) {
    int f = 12;
    printf("The factorial of %d is %d\n", f, fact(f));
    getchar();
    return 0;
}