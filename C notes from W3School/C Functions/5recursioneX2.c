#include<stdio.h>
#include<stdlib.h>

int fibo(int g) {
    if (g == 0) {
        return 0;
    }

    if (g == 1){
        return 1;
    }
    return fibo (g - 1) + fibo(g - 2);
}

int main(void) {
    int g;
    for (g = 0; g<=29; g++) {
        printf("\nNumbers are: %d \t ", fibo(g));
    }
    return 0;
}