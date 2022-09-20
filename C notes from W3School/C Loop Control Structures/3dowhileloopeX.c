#include<stdio.h>
#include<math.h>

int main()
{
    int n=1, times=5;
    
    do
    {
        printf("C do while loops: %d\n", n);
        n++;
    } while (n<=times);
    
    return 0;    
}