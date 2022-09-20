#include <stdio.h>
#include "functions_iterative.h"

int fib_iter(int n) {
    int i;
    int f1 = 0;
    int f2 = 1;
    int fi = 0;

    if (n == 0) return 0;
    if (n == 1) return 1;

    for (i=2;i<=n;i+=1) {
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }

    return fi;
}

int factorial_iter(int n) {
    int cur=1, i=0;

    for (i=2;i<=n;i+=1) {
        cur*=i;
    }

    return cur;
}

void dec_binary_iter(int num) {
    int number[50];
    int i=0;

    while (num>0) {
        number[i]=num%2;
        num/=2;
        i+=1;
    }

    i-=1;

    while (0<=i) {
        printf("%d", number[i]);
        i-=1;
    }
}