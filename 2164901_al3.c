#include <stdio.h>

int fibo(int n);

int main()
{
    fibo(20);
    return 0;
}

int fibo(int n)
{
    int res;
    if (n > 1)
        res = n + fibo(n-1);
    else
        res = 1;
    printf("%4d", res);
    return res;
}