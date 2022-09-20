#include <stdio.h>
#include "functions_recursive.h"
#include "functions_iterative.h"

int main (int argc, char** argv) {
    printf("%d\n", fib_rec(5));
    printf("%d\n\n", fib_iter(5));

    printf("%d\n", factorial_rec(5));
    printf("%d\n\n", factorial_iter(5));

    dec_binary_rec(12);
    printf("\n");
    dec_binary_iter(12);
}