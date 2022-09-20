#include <stdio.h>
#include "functions_recursive.h"

int fib_rec (int n) {
    if (n == 1 || n == 2) return 1;

    int stuff=fib_rec(n-1)+fib_rec(n-2);
    return stuff;
}

int factorial_rec (int n) {
    if (n == 1) return 1;

    int num = n*factorial_rec(n-1);
    return num;
}

void dec_binary_rec (int num) {
    if (num == 0) return;

    dec_binary_rec(num / 2);
    printf("%d", num % 2);
}